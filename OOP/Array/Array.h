#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Array {
public:
    Array(int size = 10);
    Array(const Array& other); // Копирование
    Array(Array&& other) noexcept; // Перемещение
    ~Array(); // Деструктор

    bool insert(const int index, const T& value); // Вставка
    void swap(Array& other) noexcept; // Функция свап

    int getSize() const; // Получение размера
    void input(); // Ввод
    void output() const; // Вывод

    int find(const T& value) const; // Поиск

    void bubbleSort(); // Сортировка

    bool deleteByIndex(int index); // Удаление по индексу
    bool deleteByValue(const T& value); // Удаление по значению
    void deleteAll(const T& value); // Удалить все элементы с таким значением

    T max() const; // Максимальный элемент
    T min() const; // Минимальный элемент

    T* begin(); // Итератор начала
    const T* begin() const; // Неизменяемый итератор начала
    T* end(); // Итератор конца
    const T* end() const; // Неизменяемый итератор конца

    void addInEnd(const T& value);

    void insertBefore(T* iterator, const T& value); // Вставка перед итератором
    void deleteByIterator(T* iterator); // Удаление по итератору
    bool deleteInterval(T* begin, T* end); // Удаление интервала

    bool operator!=(const Array& other) const; // Сравнение
    bool operator==(const Array& other) const; // Сравнение

    Array& operator=(const Array& other); // Копирование
    Array& operator=(Array&& other) noexcept; // Перемещение
    T& operator[](int index); // Изменяемая ссылка, доступ к индексу
    const T& operator[](int index) const; // Неизменяемая ссылка, доступ к индексу
    Array operator+(const Array& other) const; // Сложение массивов
    Array& operator+=(const Array& other); // Сложение с присваиванием

private:
    T* m_array = nullptr; // Указатель на массив 
    int m_size = 0; // Размер массива
};

