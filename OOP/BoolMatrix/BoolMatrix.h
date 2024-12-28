#pragma once
#include "../BoolVector/BoolVector.h"
#include <vector> 
class BoolMatrix {
private:
    std::vector<BoolVector> data;
    size_t rows;
    size_t cols;

public:
    // Конструкторы
    BoolMatrix(size_t rows = 0, size_t cols = 0);
    BoolMatrix(const std::vector<std::vector<bool>>& matrix);

    // Конструктор копирования
    BoolMatrix(const BoolMatrix& other);

    // Деструктор
    ~BoolMatrix();

    // Получение числа строк и столбцов
    size_t getRows() const;
    size_t getCols() const;

    // Обмен содержимого с другой матрицей
    void swap(BoolMatrix& other);

    // Ввод/вывод в консоль
    friend std::ostream& operator<<(std::ostream& os, const BoolMatrix& matrix);
    friend std::istream& operator>>(std::istream& is, BoolMatrix& matrix);

    // Вес матрицы
    size_t weight() const;
    // Конъюнкция всех строк
    BoolVector conjunction() const;
    // Дизъюнкция всех строк
    BoolVector disjunction() const;

    // Вес j-ой строки
    size_t rowWeight(size_t j) const;

    // Инверсия в i-ой компоненты j-ой строки
    void invert(size_t j, size_t i);

    // Инверсия k компонент j-ой строки, начиная с i-ой компоненты
    void invertRange(size_t j, size_t i, size_t k);

    // Установка в 0/1 i-ой компоненты j-ой строки
    void setValue(size_t j, size_t i, bool value);

    // Установка в 0/1 k компонент j-ой строки, начиная с i-ой компоненты
    void setRange(size_t j, size_t i, bool value, size_t k);
    void setAll(bool value);
    // Перегрузка оператора присваивания
    BoolMatrix& operator=(const BoolMatrix& other);

    // Перегрузка оператора доступа к строкам
    BoolVector& operator[](size_t index);
    const BoolVector& operator[](size_t index) const;

    // Перегрузка операторов побитового умножения
    BoolMatrix operator&(const BoolMatrix& other) const;

    // Перегрузка операторов побитового сложения
    BoolMatrix operator|(const BoolMatrix& other) const;

    // Перегрузка операторов побитового исключающего ИЛИ
    BoolMatrix operator^(const BoolMatrix& other) const;

    // Перегрузка построчной побитовой инверсии
    BoolMatrix operator~() const;
};
