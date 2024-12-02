#include <iostream>
#include <algorithm>
#include "BoolMatrix.h"

BoolMatrix::BoolMatrix(size_t rows, size_t cols)
    : rows(rows)
    , cols(cols)
    , data(rows, BoolVector(cols))
{}

BoolMatrix::BoolMatrix(const std::vector<std::vector<bool>>& matrix)
    : rows(matrix.size()),
    cols(0), // Изначально устанавливаем cols в 0
    data(matrix.size()) // Предварительно выделяем память для data
{
    if (!matrix.empty()) { // Проверяем, не пустой ли matrix
        cols = matrix[0].size(); // Если не пустой, присваиваем значение cols
    }

    std::transform(
        matrix.begin(),
        matrix.end(),
        data.begin(),
        [](const std::vector<bool>& row) -> BoolVector {
            return BoolVector(row);
        }
    );
}

BoolMatrix::BoolMatrix(const BoolMatrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

BoolMatrix::~BoolMatrix() {}

size_t BoolMatrix::getRows() const { return rows; }

size_t BoolMatrix::getCols() const { return cols; }

void BoolMatrix::swap(BoolMatrix& other) {
    std::swap(rows, other.rows);
    std::swap(cols, other.cols);
    std::swap(data, other.data);
}


size_t BoolMatrix::weight() const {
    size_t totalWeight = 0;

    for (const auto& row : data) {
        totalWeight += row.weight();
    }

    return totalWeight;
}

BoolVector BoolMatrix::conjunction() const {
    if (rows == 0) return BoolVector(cols);

    BoolVector result = data[0];

    for (size_t i = 1; i < rows; ++i) {
        result &= data[i];
    }

    return result;
}

BoolVector BoolMatrix::disjunction() const {
    if (rows == 0) return BoolVector(cols);

    BoolVector result = data[0];

    for (size_t i = 1; i < rows; ++i) {
        result |= data[i];
    }

    return result;
}

size_t BoolMatrix::rowWeight(size_t j) const {
    if (j >= rows) {
        throw std::invalid_argument("Индекс строки выходит за пределы диапазона");
    }
    return data[j].weight();
}

void BoolMatrix::invert(size_t j, size_t i) {
    if (j >= rows || i >= cols) {
        throw std::invalid_argument("Индекс выходит за пределы диапазона");
    }
    data[j][i] = !data[j][i];
}

void BoolMatrix::invertRange(size_t j, size_t i, size_t k) {
    if (j >= rows || i >= cols || (i + k > cols)) {
        throw std::invalid_argument("Индекс выходит за пределы диапазона");
    }
    for (size_t index = 0; index < k; ++index) {
        data[j][i + index] = !data[j][i + index];
    }
}

void BoolMatrix::setValue(size_t j, size_t i, bool value) {
    if (j >= rows || i >= cols) {
        throw std::invalid_argument("Индекс выходит за пределы диапазона");
    }
    data[j][i] = value;
}

void BoolMatrix::setRange(size_t j, size_t i, bool value, size_t k) {
    if (j >= rows || i >= cols || (i + k > cols)) {
        throw std::invalid_argument("Индекс выходит за пределы диапазона");
    }
    for (size_t index = 0; index < k; ++index) {
        data[j][i + index] = value;
    }
}

BoolMatrix& BoolMatrix::operator=(const BoolMatrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data; // Копирование содержимого другой матрицы
    }
    return *this;
}

BoolVector& BoolMatrix::operator[](size_t index) {
    if (index >= rows) {
        throw std::invalid_argument("Индекс строки выходит за пределы диапазона");
    }
    return data[index];
}

const BoolVector& BoolMatrix::operator[](size_t index) const {
    if (index >= rows) {
        throw std::invalid_argument("Индекс строки выходит за пределы диапазона");
    }
    return data[index];
}

BoolMatrix BoolMatrix::operator&(const BoolMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Матрицы должны быть одного размера");
    }

    BoolMatrix result(rows, cols); // Результирующая матрица

    for (size_t i = 0; i < rows; ++i) {
        result.data[i] = data[i] & other.data[i]; // Логическое И поэлементно для всех строк
    }

    return result;
}

BoolMatrix BoolMatrix::operator|(const BoolMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Матрицы должны быть одного размера");
    }

    BoolMatrix result(rows, cols);

    for (size_t i = 0; i < rows; ++i) {
        result.data[i] = data[i] | other.data[i]; // Логическое ИЛИ поэлементно для всех строк
    }

    return result;
}

BoolMatrix BoolMatrix::operator^(const BoolMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Матрицы должны быть одного размера");
    }

    BoolMatrix result(rows, cols);

    for (size_t i = 0; i < rows; ++i) {
        result.data[i] = data[i] ^ other.data[i]; // Логическое исключающее ИЛИ поэлементно для всех строк
    }

    return result;
}

BoolMatrix BoolMatrix::operator~() const {
    BoolMatrix result(rows, cols);

    for (size_t i = 0; i < rows; ++i) {
        result.data[i] =; // Инверсия всех строк матрицы
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const BoolMatrix& matrix) {
    for (const auto& row : matrix.data) {
        os << row << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, BoolMatrix& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        is >> matrix[i];
        
    }
    return is;
}