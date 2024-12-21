#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Array {
public:
    Array(int size = 10);
    Array(const Array& other); // �����������
    Array(Array&& other) noexcept; // �����������
    ~Array(); // ����������

    bool insert(const int index, const T& value); // �������
    void swap(Array& other) noexcept; // ������� ����

    int getSize() const; // ��������� �������
    void input(); // ����
    void output() const; // �����

    int find(const T& value) const; // �����

    void bubbleSort(); // ����������

    bool deleteByIndex(int index); // �������� �� �������
    bool deleteByValue(const T& value); // �������� �� ��������
    void deleteAll(const T& value); // ������� ��� �������� � ����� ���������

    T max() const; // ������������ �������
    T min() const; // ����������� �������

    T* begin(); // �������� ������
    const T* begin() const; // ������������ �������� ������
    T* end(); // �������� �����
    const T* end() const; // ������������ �������� �����

    void addInEnd(const T& value);

    void insertBefore(T* iterator, const T& value); // ������� ����� ����������
    void deleteByIterator(T* iterator); // �������� �� ���������
    bool deleteInterval(T* begin, T* end); // �������� ���������

    bool operator!=(const Array& other) const; // ���������
    bool operator==(const Array& other) const; // ���������

    Array& operator=(const Array& other); // �����������
    Array& operator=(Array&& other) noexcept; // �����������
    T& operator[](int index); // ���������� ������, ������ � �������
    const T& operator[](int index) const; // ������������ ������, ������ � �������
    Array operator+(const Array& other) const; // �������� ��������
    Array& operator+=(const Array& other); // �������� � �������������

private:
    T* m_array = nullptr; // ��������� �� ������ 
    int m_size = 0; // ������ �������
};

