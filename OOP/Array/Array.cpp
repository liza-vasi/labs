#include <iostream>
#include "Array.h"
#include <stdexcept>
Array::Array(int size)
{
	if (size < 0)
	{
		size = -size;
	}
	m_size = size;
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = 0;
	}
}

Array::~Array()
{
	delete[] m_array;
}
Array::Array(const Array& other)
{
	m_size = other.m_size;
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = other.m_array[i];
	}
}

Array::Array(Array&& other) noexcept
{
	m_size = other.m_size;
	m_array = other.m_array;

	other.m_size = 0;
	other.m_array = nullptr;
}



int& Array::operator[](int index) {// возвращение элемента по его индекску
	if (index < 0 && index >= m_size) {
		std::cout << "index error< undex=0\n";
		return m_array[0];
	}
	else {
		return m_array[index];
	}
}
const int& Array::operator[](int index) const
{
	if (index < 0 && index >= m_size) {
		std::cout << "index error< undex=0\n";
		return m_array[0];
	}
	else {
		return m_array[index];
	}
}

bool Array::insert(const int index, const int& value)
{
	if (index < 0 || index > m_size)
	{
		return false;
	}

	int* newArray = new int[m_size + 1];
	for (int i = 0; i <= index; ++i)
	{
		newArray[i] = m_array[i];
	}
	newArray[index] = value;
	for (int i = index + 1; i < m_size + 1; ++i)
	{
		newArray[i] = m_array[i - 1];
	}

	delete[] m_array;

	m_array = newArray;
	m_size++;

	return true;
}
void Array::swap(Array& other) noexcept
{
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
}

Array& Array::operator=(const Array& other)
{
	if (m_size == other.m_size)
	{
		for (int i = 0; i < m_size; ++i)
		{
			m_array[i] = other.m_array[i];
		}
	}
	else
	{
		Array copy(other);
		swap(copy);
	}
	return *this;
}

Array& Array::operator=(Array&& other) noexcept
{
	//std::cout << this << ": " << "Array::operator=(Array&& other) begin \n";
	std::cout << "other: " << &other << " \n";
	swap(other);
	//std::cout << this << ": " << "Array::operator=(Array&& other) end \n";
	return *this;
}


Array Array::operator+(const Array& other) const
{
	Array result(m_size + other.m_size);
	for (int i = 0; i < m_size; i++)
	{
		result[i] = m_array[i];
	}
	for (int i = 0; i < other.m_size; i++)
	{
		result[m_size + i] = other[i];
	}
	return result;
}

Array& Array::operator+=(const Array& other)
{
	operator+(other).swap(*this);
	return *this;
}

int Array:: getSize() const
{
	return m_size;
}

void Array:: input() {
	for (int i = 0; i < m_size; i++) {
		std::cin >> m_array[i];
	}
}

void Array::output() const {
	for (int i = 0; i < m_size; i++) {
		std::cout << m_array[i] << " ";
	}
	std::cout << '\n';
}

bool Array::operator==(const Array& other) const {
	if (m_size != other.m_size) return false;

	for (int i = 0; i < m_size; i++) {
		if (m_array[i] != other.m_array[i]) return false;
	}

	return true;
}

bool Array::operator!=(const Array& other) const {
	return !(*this == other);
}

// Поиск элемента
int Array::find(int value) const {
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == value) {
			return i;
		}
	}
	return -1; 
}

void Array::bubleSort() {
	for (size_t i = 0; i < m_size - 1; i++) {
		for (size_t j = 0; j < m_size - i - 1; j++) {
			if (m_array[j] > m_array[j + 1]) {
				std::swap(m_array[j], m_array[j + 1]);
			}
		}
	}
}

bool Array::deleteByIndex(int index) {
	if (index >= m_size || index < 0)
	{
		return false;
	}
	for (int i = index; i <= m_size - 1; i++) {
		m_array[i] = m_array[i + 1];
	}
	m_size--;
	return true;
}

// Удаление элемента по значению
bool Array:: deleteByValue(int value) {
	int index = find(value);
	if (index == -1)
	{
		return false;
	}
	return deleteByIndex(index);
}

void Array::deleteAll(int value) {
	while (true) {
		int index = find(value);
		if (index == -1)
		{
			break;
		}
		deleteByIndex(index);
	}
}

int Array::max() const {
	if (m_size == 0) {
		throw std::runtime_error("Массиы пустой");
	}

	int max = m_array[0];
	for (int i = 1; i < m_size; i++) { 
		if (m_array[i] > max) {
			max = m_array[i];
		}
	}
	return max;
}

int Array::min() const {
	if (m_size == 0) {
		throw std::runtime_error("Массив пустой");
	}

	int min = m_array[0]; 
	for (int i = 1; i < m_size; i++) {
		if (m_array[i] < min) {
			min = m_array[i];
		}
	}
	return min;
}

int* Array::begin() { 
	return m_array;
}
const int* Array::begin() const { 
	return m_array; 
}

int* Array::end() {
	return m_array + m_size; 
}
const int* Array::end() const {
	return m_array + m_size;
}

void Array::insertBefore(int* iterator, int value) {
	int index = iterator - m_array;
	insert(index, value);
}

void Array::deleteByIterator(int* iterator) {
	int index = iterator - m_array;
	deleteByIndex(index);
}

bool Array:: deleteInterval(int* begin, int* end) {
	if (begin == nullptr || end == nullptr || begin > end) {
		return false;
	}
	int startIndex = begin - m_array;
	int endIndex = end - m_array;

	for (int i = startIndex; i <= endIndex; i++) {
		deleteByIndex(i);
	}
}


void Array::addInEnd(int value) {
	insert(m_size, value);
} 
