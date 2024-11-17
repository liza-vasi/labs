#pragma once
#include <stdexcept>
#include <cstring>

class BoolVector {
public:
    class Rank;

public:
    using Cell = unsigned char;
    static const int CellSize = 8; // sizeof(Cell) * 8
    BoolVector(int length = CellSize);// Конструктор по умолчанию
    BoolVector(int length, bool value);
    BoolVector(const BoolVector& other);// Конструктор копирования
    ~BoolVector();// Деструктор
    int length() const;// Получение длины вектора
    void swap(BoolVector& other);// Обмен содержимым с другим вектором
    bool bitValue(int index) const;// Получение значения бита по индексу
    void setBitValue(int index, bool value);// Установка значения бита по индексу
    BoolVector& operator=(const BoolVector& other);// Перегрузка оператора присваивания
    Rank operator[](int index);// Перегрузка оператора доступа к компонентам
    // Потоковый ввод-вывод
    friend std::ostream& operator<<(std::ostream& os, const BoolVector& bv);
    friend std::istream& operator>>(std::istream& is, BoolVector& bv);

    // Инверсия i-ой компоненты
    void invertBit(int index);

    // Установка в 0/1 i-ой компоненты
    void setBit(int index, bool value);

    // Установка в 0/1 k компонент, начиная с i-ой
    void setBits(int index, int count, bool value);

    // Установка в 0/1 всех компонент вектора
    void setAll(bool value);

    // Вес вектора (количество единиц)
    int weight() const;

    // Побитовое умножение (&, &=)
    BoolVector operator&(const BoolVector& other) const;
    BoolVector& operator&=(const BoolVector& other);

    // Побитовое сложение (|, |=)
    BoolVector operator|(const BoolVector& other) const;
    BoolVector& operator|=(const BoolVector& other);

    // Побитовое исключающее ИЛИ (^, ^=)
    BoolVector operator^(const BoolVector& other) const;
    BoolVector& operator^=(const BoolVector& other);

    // Побитовые сдвиги (<<, >>, <<=, >>=)
    BoolVector operator<<(int count) ;
    BoolVector operator>>(int count) ;
    BoolVector& operator>>=(int count);
    BoolVector& operator<<=(int count);
    // Побитовая инверсия (~)
    BoolVector operator~() const;
private:
    // Вспомогательные методы
    int _excessRankCount() const;
    static Cell _mask(int index);

private:
    Cell* m_cells = nullptr;// Массив ячеек
    int m_cellCount = 0;// Количество ячеек
    int m_length = 0;// Количество бит
};


class BoolVector::Rank
{
public:
    Rank() = default;
    Rank(Cell* cell, Cell mask);
    Rank& operator=(const Rank& other);
    Rank& operator=(bool value);
    operator bool() const;

private:
    Cell* m_cell = nullptr;
    Cell m_mask = 0;
};