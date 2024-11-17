#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Array {
public:
    Array(int size = 10);
    Array(const Array& other);//копирование
    Array(Array&& other)noexcept;//перемещение
    ~Array();//деструктор

    bool insert(const int index, const int& value);//вставка ++
    void swap(Array& other) noexcept;//функция свап  ++

    int getSize() const;//получение размера ++
    void input();//ввод ++
    void output() const;//вывод ++

    int find(int value) const;//поиск   ++

    void bubleSort();//соритировка   ++

    bool deleteByIndex(int index);//удаление по индексу ++
    bool deleteByValue(int value);//удаление по значению ++
    void deleteAll(int value);// удалить все элементы с таким значением ++

    int max() const;// максимальный элемент ++
    int min() const;// минимальный элемент ++

    int* begin();//итератор начала
    const int* begin() const;// неизменяемый итератор начала
    int* end();//итератор конца
    const int* end() const;//неизменяемый итератор конц

    void addInEnd(int value);

    void insertBefore(int* iterator, int value);//вставка перед итератором ++
    void deleteByIterator(int* iterator);//удаление по итератору++
    bool deleteInterval(int* begin, int* end);//удаление интервала ++


    bool operator!=(const Array& other) const;//сравнение ++
    bool operator==(const Array& other) const;//сравнение  ++

    Array& operator=(const Array& other);//копирование ++
    Array& operator=(Array&& other) noexcept;//перемещение
    int& operator[](int index);//изменяемая ссылка, доступ к индексу
    const int& operator[](int index) const;//неизменяемая поэтому const, тоже доступ к индексу
    Array operator+(const Array& other) const;//сложение массивов
    Array& operator+=(const Array& other);//сложение с присваиванием

private:
    int* m_array = nullptr;//указатель на массив 
    int m_size = 0;//размер массива
    
};