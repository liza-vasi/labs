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
    List(); // ����������� �� ���������
    List(const T* array, size_t size); // ����������� �� �������
    List(const List& other); // ����������� �����������
    ~List(); // ����������

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    int size() const;//������
    void clear();
    void append(const T& value);
    void print() const;

    void swap(List& other); // ����� ����������� � ������ �������
    iterator find(const T& key); // ����� �������� �� �����
    void push_head(const T& value); // ���������� �������� � ������
    void push_tail(const T& value); // ���������� �������� � �����
    void insert_after(iterator pos, const T& value); // ������� ����� ���������
    //������� ����� �����
    // �������� �� ������
    //�������� �� ������
    void remove(iterator pos); // �������� �� ���������
    void remove(const T& key); // �������� �� �����
    void remove_range(iterator first, iterator last); // �������� ���������

    T min() const; // ����� ������������ ��������
    T max() const; // ����� ������������� ��������
    bool isEmpty() const; // �������� �� �������
    void sort(); // ���������� ������

    List& operator=(const List& other); // ������������
    T& operator[](size_t index); // ��������� ������ �� �������
    bool operator==(const List& other) const; // ���������
    bool operator!=(const List& other) const; // �����������
    List operator+(const List& other) const; // ������������ �������
    List& operator+=(const List& other); // ������������ � �������������

private:
    int m_size = 0;
    Node* m_head = nullptr;
    Node* m_tail = nullptr;

};

// ����������� ��������� ����
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

// ����������� ���������
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