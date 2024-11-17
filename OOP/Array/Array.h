#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Array {
public:
    Array(int size = 10);
    Array(const Array& other);//�����������
    Array(Array&& other)noexcept;//�����������
    ~Array();//����������

    bool insert(const int index, const int& value);//������� ++
    void swap(Array& other) noexcept;//������� ����  ++

    int getSize() const;//��������� ������� ++
    void input();//���� ++
    void output() const;//����� ++

    int find(int value) const;//�����   ++

    void bubleSort();//�����������   ++

    bool deleteByIndex(int index);//�������� �� ������� ++
    bool deleteByValue(int value);//�������� �� �������� ++
    void deleteAll(int value);// ������� ��� �������� � ����� ��������� ++

    int max() const;// ������������ ������� ++
    int min() const;// ����������� ������� ++

    int* begin();//�������� ������
    const int* begin() const;// ������������ �������� ������
    int* end();//�������� �����
    const int* end() const;//������������ �������� ����

    void addInEnd(int value);

    void insertBefore(int* iterator, int value);//������� ����� ���������� ++
    void deleteByIterator(int* iterator);//�������� �� ���������++
    bool deleteInterval(int* begin, int* end);//�������� ��������� ++


    bool operator!=(const Array& other) const;//��������� ++
    bool operator==(const Array& other) const;//���������  ++

    Array& operator=(const Array& other);//����������� ++
    Array& operator=(Array&& other) noexcept;//�����������
    int& operator[](int index);//���������� ������, ������ � �������
    const int& operator[](int index) const;//������������ ������� const, ���� ������ � �������
    Array operator+(const Array& other) const;//�������� ��������
    Array& operator+=(const Array& other);//�������� � �������������

private:
    int* m_array = nullptr;//��������� �� ������ 
    int m_size = 0;//������ �������
    
};