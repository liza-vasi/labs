#pragma once
#include "../BoolVector/BoolVector.h"
#include <vector> 
class BoolMatrix {
private:
    std::vector<BoolVector> data;
    size_t rows;
    size_t cols;

public:
    // ������������
    BoolMatrix(size_t rows = 0, size_t cols = 0);
    BoolMatrix(const std::vector<std::vector<bool>>& matrix);

    // ����������� �����������
    BoolMatrix(const BoolMatrix& other);

    // ����������
    ~BoolMatrix();

    // ��������� ����� ����� � ��������
    size_t getRows() const;
    size_t getCols() const;

    // ����� ����������� � ������ ��������
    void swap(BoolMatrix& other);

    // ����/����� � �������
    friend std::ostream& operator<<(std::ostream& os, const BoolMatrix& matrix);
    friend std::istream& operator>>(std::istream& is, BoolMatrix& matrix);

    // ��� �������
    size_t weight() const;
    // ���������� ���� �����
    BoolVector conjunction() const;
    // ���������� ���� �����
    BoolVector disjunction() const;

    // ��� j-�� ������
    size_t rowWeight(size_t j) const;

    // �������� � i-�� ���������� j-�� ������
    void invert(size_t j, size_t i);

    // �������� k ��������� j-�� ������, ������� � i-�� ����������
    void invertRange(size_t j, size_t i, size_t k);

    // ��������� � 0/1 i-�� ���������� j-�� ������
    void setValue(size_t j, size_t i, bool value);

    // ��������� � 0/1 k ��������� j-�� ������, ������� � i-�� ����������
    void setRange(size_t j, size_t i, bool value, size_t k);
    void setAll(bool value);
    // ���������� ��������� ������������
    BoolMatrix& operator=(const BoolMatrix& other);

    // ���������� ��������� ������� � �������
    BoolVector& operator[](size_t index);
    const BoolVector& operator[](size_t index) const;

    // ���������� ���������� ���������� ���������
    BoolMatrix operator&(const BoolMatrix& other) const;

    // ���������� ���������� ���������� ��������
    BoolMatrix operator|(const BoolMatrix& other) const;

    // ���������� ���������� ���������� ������������ ���
    BoolMatrix operator^(const BoolMatrix& other) const;

    // ���������� ���������� ��������� ��������
    BoolMatrix operator~() const;
};
