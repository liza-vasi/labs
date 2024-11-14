#include <assert.h>
#include <iostream>
#include <utility>
#include "BoolVector.h"

BoolVector::BoolVector(int length)
	: m_length(length)
{
	m_cellCount = m_length / CellSize;
	if (m_length % CellSize != 0)
	{
		m_cellCount++;
	}

	m_cells = new Cell[m_cellCount];
}
BoolVector::BoolVector(int length, bool value) : m_length(length) {
    m_cellCount = (length + CellSize - 1) / CellSize; 
    m_cells = new Cell[m_cellCount](); 

    if (value) {
        setAll(true); 
    }
    else {
        setAll(false); 
    }
}
BoolVector::BoolVector(const BoolVector& other)
{
	m_cellCount = other.m_cellCount;
	m_length = other.m_length;
	m_cells = new Cell[m_cellCount];
	for (int i = 0; i < m_cellCount; i++)
	{
		m_cells[i] = other.m_cells[i];
	}
}

BoolVector::~BoolVector()
{
	delete[] m_cells;
}

int BoolVector::length() const
{
	return m_length;
}

void BoolVector::swap(BoolVector& other)
{
	std::swap(m_cells, other.m_cells);
	std::swap(m_cellCount, other.m_cellCount);
	std::swap(m_length, other.m_length);
}

bool BoolVector::bitValue(int index) const
{
	assert(index >= 0 && index < m_length);
	Cell mask = _mask(index);
	return m_cells[index / CellSize] & mask;
}

void BoolVector::setBitValue(int index, bool value)
{
	assert(index >= 0 && index < m_length);
	Cell mask = _mask(index);
	if (value)
	{
		m_cells[index / CellSize] |= mask;
	}
	else
	{
		m_cells[index / CellSize] &= ~mask;
	}
}

BoolVector& BoolVector::operator=(const BoolVector& other)
{
	return *this;
}

BoolVector::Rank BoolVector::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return Rank(&m_cells[index / CellSize], _mask(index));
}

int BoolVector::_excessRankCount() const
{
	return (m_cellCount * CellSize - m_length);
}

BoolVector::Cell BoolVector::_mask(int index)
{
	Cell mask = 1;
	mask <<= CellSize - 1 - (index % CellSize);
	return mask;
}

BoolVector::Rank::Rank(Cell* cell, Cell mask)
	: m_cell(cell)
	, m_mask(mask)
{
	assert(m_cell != nullptr);
	assert(m_mask > 0);
}

BoolVector::Rank& BoolVector::Rank::operator=(const Rank& other)
{
	return operator=(static_cast<bool>(other));
}

BoolVector::Rank& BoolVector::Rank::operator=(bool value)
{
	if (value)
	{
		*m_cell |= m_mask;
	}
	else
	{
		*m_cell &= ~m_mask;
	}
	return *this;
}

BoolVector::Rank::operator bool() const
{
	return (*m_cell & m_mask) != 0;
}



// Потоковый ввод-вывод
std::ostream& operator<<(std::ostream& os, const BoolVector& bv) {
    for (int i = 0; i < bv.length(); i++) {
        os << bv.bitValue(i);
        if (i < bv.length() - 1) os << " ";
    }
    return os;
}

// Реализация оператора ввода >>
std::istream& operator>>(std::istream& is, BoolVector& bv) {
    for (int i = 0; i < bv.length(); i++) {
        bool value;
        is >> value;
        bv.setBitValue(i, value);
    }
    return is;
}

// Инверсия i-ой компоненты
void BoolVector::invertBit(int index) {
    if (index < 0 || index >= m_length) throw std::out_of_range("Index out of range");
    setBitValue(index, !bitValue(index));
}

// Установка в 0/1 i-ой компоненты
void BoolVector::setBit(int index, bool value) {
    setBitValue(index, value);
}

// Установка в 0/1 k компонент, начиная с i-ой
void BoolVector::setBits(int index, int count, bool value) {
    if (index < 0 || index + count > m_length) throw std::out_of_range("Index out of range");

    for (int i = index; i < index + count; ++i) {
        setBitValue(i, value);
    }
}

// Установка в 0/1 всех компонент вектора
void BoolVector::setAll(bool value) {
    for (int i = 0; i < m_length; ++i) {
        setBitValue(i, value);
    }
}

// Вес вектора 
int BoolVector::weight() const {
    int count = 0;
    for (int i = 0; i < m_length; ++i) {
        count += bitValue(i);
    }
    return count;
}

// Побитовое умножение (&)
BoolVector BoolVector::operator&(const BoolVector& other) const {
    if (m_length != other.m_length) throw std::invalid_argument("Vectors must have the same length");

    BoolVector result(m_length);

    for (int i = 0; i < m_cellCount; ++i) {
        result.m_cells[i] = this->m_cells[i] & other.m_cells[i];
    }

    return result;
}

BoolVector& BoolVector::operator&=(const BoolVector& other) {
    if (m_length != other.m_length) throw std::invalid_argument("Vectors must have the same length");

    for (int i = 0; i < m_cellCount; ++i) {
        this->m_cells[i] &= other.m_cells[i];
    }

    return *this;
}

// Побитовое сложение (|)
BoolVector BoolVector::operator|(const BoolVector& other) const {
    if (m_length != other.m_length) throw std::invalid_argument("Vectors must have the same length");

    BoolVector result(m_length);

    for (int i = 0; i < m_cellCount; ++i) {
        result.m_cells[i] = this->m_cells[i] | other.m_cells[i];
    }

    return result;
}

BoolVector& BoolVector::operator|=(const BoolVector& other) {
    if (m_length != other.m_length) throw std::invalid_argument("Vectors must have the same length");

    for (int i = 0; i < m_cellCount; ++i) {
        this->m_cells[i] |= other.m_cells[i];
    }

    return *this;
}

// Побитовое исключающее ИЛИ (^)
BoolVector BoolVector::operator^(const BoolVector& other) const {
    if (m_length != other.m_length) throw std::invalid_argument("Vectors must have the same length");

    BoolVector result(m_length);

    for (int i = 0; i < m_cellCount; ++i) {
        result.m_cells[i] = this->m_cells[i] ^ other.m_cells[i];
    }

    return result;
}

BoolVector& BoolVector::operator^=(const BoolVector& other) {
    if (m_length != other.m_length) throw std::invalid_argument("Vectors must have the same length");

    for (int i = 0; i < m_cellCount; ++i) {
        this->m_cells[i] ^= other.m_cells[i];
    }

    return *this;
}

// Побитовые сдвиги (<<)
BoolVector BoolVector::operator<<=(int count) const {
    if (count < 0) {
        return operator>>=(-count);
    }
    else if (count >= m_length) {
        BoolVector result(m_length);
        return result;
    }
    else if (count == 0) {
        return *this;
    }

    BoolVector that = *this; 
    for (int i = 0; i < m_length - count; ++i) {
        that[i] = that[i + count]; 
    }

    for (int i = m_length - count; i < m_length; ++i) {
        that[i] = 0; 
    }

    return that; 
}



BoolVector BoolVector::operator>>=(int count) const {
    if (count < 0) {
        return operator<<=(-count);
    }
    else if (count >= m_length) {
        return BoolVector(m_length); 
    }
    else if (count == 0) {
        return *this; 
    }

    BoolVector that = *this;
    for (int i = m_length - 1; i >= count; i--) {
        that[i] = that[i - count];
    }

    for (int i = 0; i < count; i++) {
        that[i] = false; 
    }

    return that;
}

BoolVector& BoolVector::operator<<(int count) {
    *this = operator<<=(count); 
    return *this;
}

BoolVector& BoolVector::operator>>(int count) {
    *this = operator>>=(count); 
    return *this;
}

BoolVector BoolVector::operator~() const {
    BoolVector result(m_length);

    for (int i = 0; i < m_cellCount; ++i) {
        result.m_cells[i] = ~this->m_cells[i];
    }

    return result;
}

