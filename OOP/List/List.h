#pragma once

#include <iostream>
#include <algorithm> 
#include <iterator>  
#include <vector>    
#include <stdexcept> 

template <typename T>
class List {
    struct Node;

public:
    template <typename ItemType>
    class TemplateIterator;
    using iterator = TemplateIterator<T>;
    using const_iterator = TemplateIterator<const T>;

public:
    List(); // Конструктор по умолчанию
    List(const T* array, size_t size); // Конструктор из массива
    List(const List& other); // Конструктор копирования
    ~List(); // Деструктор

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    int size() const;//размер
    void clear();
    void append(const T& value);
    void print() const;

    void swap(List& other); // Обмен содержимого с другим списком
    iterator find(const T& key); // Поиск элемента по ключу
    void push_head(const T& value); // Добавление элемента в голову
    void push_tail(const T& value); // Добавление элемента в хвост
    void insert_after(iterator pos, const T& value); // Вставка после итератора
    //Вставка после ключа
    // удаление из головы
    //удаление из хвоста
    void remove(iterator pos); // Удаление по итератору
    void remove(const T& key); // Удаление по ключу
    void remove_range(iterator first, iterator last); // Удаление диапазона

    T min() const; // Поиск минимального элемента
    T max() const; // Поиск максимального элемента
    bool isEmpty() const; // Проверка на пустоту
    void sort(); // Сортировка списка

    List& operator=(const List& other); // Присваивание
    T& operator[](size_t index); // Получение ссылки на элемент
    bool operator==(const List& other) const; // Сравнение
    bool operator!=(const List& other) const; // Неравенство
    List operator+(const List& other) const; // Конкатенация списков
    List& operator+=(const List& other); // Конкатенация с присваиванием

private:
    int m_size = 0;
    Node* m_head = nullptr;
    Node* m_tail = nullptr;

};

// Определение структуры узла
template <typename T>
struct List<T>::Node {
    Node(Node* next = nullptr, Node* prev = nullptr)
        : next(next), prev(prev) {}

    Node(const T& value, Node* next = nullptr, Node* prev = nullptr)
        : value(value), next(next), prev(prev) {}

    T value;
    Node* next = nullptr;
    Node* prev = nullptr;
};

// Определение итератора
template <typename T>
template <typename ItemType>
class List<T>::TemplateIterator {
public:
    using value_type = ItemType;
    using reference = ItemType&;
    using pointer = ItemType*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = int;

    TemplateIterator(Node* node) : m_node(node) {}

    ItemType& operator*() { return m_node->value; }
    const ItemType& operator*() const { return m_node->value; }

    TemplateIterator& operator++() {
        m_node = m_node->next;
        return *this;
    }

    TemplateIterator& operator--() {
        m_node = m_node->prev;
        return *this;
    }

    bool operator==(const TemplateIterator& other) const { return m_node == other.m_node; }
    bool operator!=(const TemplateIterator& other) const { return m_node != other.m_node; }

protected:
    Node* m_node = nullptr;
};