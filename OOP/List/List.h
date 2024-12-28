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
    List(); // ??????????? ?? ?????????
    List(const T* array, size_t size); // ??????????? ?? ???????
    List(const List& other); // ??????????? ???????????
    ~List(); // ??????????

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    int size() const;//??????
    void clear();
    void append(const T& value);
    void print() const;

    void swap(List& other); // ????? ??????????? ? ?????? ???????
    iterator find(const T& key); // ????? ???????? ?? ?????
    void push_head(const T& value); // ?????????? ???????? ? ??????
    void push_tail(const T& value); // ?????????? ???????? ? ?????
    void insert_after(iterator pos, const T& value); // ??????? ????? ?????????
    void push_after(const T& key, const T& value); // Âñòàâêà ïîñëå êëþ÷à
    void remove_head(); // Óäàëåíèå èç ãîëîâû
    void remove_tail(); // Óäàëåíèå èç õâîñòà
    void remove(iterator pos); // ???????? ?? ?????????
    void remove(const T& key); // ???????? ?? ?????
    void remove_range(iterator first, iterator last); // ???????? ?????????

    T min() const; // ????? ???????????? ????????
    T max() const; // ????? ????????????? ????????
    bool isEmpty() const; // ???????? ?? ???????
    void sort(); // ?????????? ??????

    List& operator=(const List& other); // ????????????
    T& operator[](size_t index); // ????????? ?????? ?? ???????
    bool operator==(const List& other) const; // ?????????
    bool operator!=(const List& other) const; // ???????????
    List operator+(const List& other) const; // ???????????? ???????
    List& operator+=(const List& other); // ???????????? ? ?????????????

private:
    int m_size = 0;
    Node* m_head = nullptr;
    Node* m_tail = nullptr;

};

// ??????????? ????????? ????
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

// ??????????? ?????????
template <typename T>
template <typename ItemType>
class List<T>::TemplateIterator {
public:
    Node* getNode() const {
        return m_node;
    }
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


template <typename T>
List<T>::List()
    : m_head(new Node()), m_tail(new Node()) {
    m_head->next = m_tail;
    m_tail->prev = m_head;
}

template <typename T>
List<T>::List(const T* array, size_t size) : List() {
    for (size_t i = 0; i < size; ++i) {
        append(array[i]);
    }
}

template <typename T>
List<T>::List(const List& other) : List() {
    for (Node* current = other.m_head->next; current != other.m_tail; current = current->next) {
        append(current->value);
    }
}

template <typename T>
List<T>::~List() {
    clear();
    delete m_head;
    delete m_tail;
}

template <typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator(m_head->next);
}

template <typename T>
typename List<T>::iterator List<T>::end() {
    return iterator(m_tail);
}

template <typename T>
typename List<T>::const_iterator List<T>::begin() const {
    return const_iterator(m_head->next);
}

template <typename T>
typename List<T>::const_iterator List<T>::end() const {
    return const_iterator(m_tail);
}

template <typename T>
int List<T>::size() const {
    return m_size;
}

template <typename T>
void List<T>::clear() {
    while (m_head->next != m_tail) {
        remove(begin());
    }
}

template <typename T>
void List<T>::append(const T& value) {
    Node* node = new Node(value, m_tail, m_tail->prev);
    m_tail->prev->next = node;
    m_tail->prev = node;
    ++m_size;
}

template <typename T>
void List<T>::print() const {
    for (Node* current = m_head->next; current != m_tail; current = current->next) {
        std::cout << current->value << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void List<T>::swap(List& other) {
    std::swap(m_head, other.m_head);
    std::swap(m_tail, other.m_tail);
    std::swap(m_size, other.m_size);
}

template <typename T>
typename List<T>::iterator List<T>::find(const T& key) {
    for (Node* current = m_head->next; current != m_tail; current = current->next) {
        if (current->value == key) {
            return iterator(current);
        }
    }
    return end(); // Åñëè íå íàéäåíî, âîçâðàùàåì end()
}

template <typename T>
void List<T>::push_head(const T& value) {
    Node* node = new Node(value, m_head->next, m_head);
    m_head->next->prev = node;
    m_head->next = node;
    ++m_size;
}

template <typename T>
void List<T>::push_tail(const T& value) {
    append(value);
}

template <typename T>
void List<T>::insert_after(iterator pos, const T& value) {
    Node* node = new Node(value, pos.m_node->next, pos.m_node);
    pos.m_node->next->prev = node;
    pos.m_node->next = node;
    ++m_size;
}

template <typename T>
void List<T>::remove(iterator pos) {
    if (pos.getNode() == m_head || pos.getNode() == m_tail) {
        return; // Íåëüçÿ óäàëÿòü ôèêòèâíûå óçëû
    }
    Node* toDelete = pos.getNode();

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    delete toDelete;
    --m_size;
}

template <typename T>
void List<T>::remove(const T& key) {
    for (Node* current = m_head->next; current != m_tail; current = current->next) {
        if (current->value == key) {
            remove(iterator(current));
            break; // Óäàëÿåì òîëüêî ïåðâîå âõîæäåíèå
        }
    }
}

template <typename T>
void List<T>::remove_range(iterator first, iterator last) {
    while (first != last) {
        remove(first++);
    }
}

template <typename T>
T List<T>::min() const {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }

    T minValue = m_head->next->value;

    for (Node* current = m_head->next; current != m_tail; current = current->next) {
        if (current->value < minValue) {
            minValue = current->value;
        }
    }

    return minValue;
}

template <typename T>
T List<T>::max() const {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }

    T maxValue = m_head->next->value;

    for (Node* current = m_head->next; current != m_tail; current = current->next) {
        if (current->value > maxValue) {
            maxValue = current->value;
        }
    }

    return maxValue;
}

template <typename T>
bool List<T>::isEmpty() const {
    return m_size == 0;
}

template <typename T>
void List<T>::sort() {
    if (isEmpty()) return;

    std::vector<T> values;
    for (Node* current = m_head->next; current != m_tail; current = current->next) {
        values.push_back(current->value);
    }

    std::sort(values.begin(), values.end());
    clear(); // Î÷èùàåì òåêóùèé ñïèñîê

    for (const auto& value : values) {
        append(value);
    }
}

// Ïåðåãðóçêà îïåðàòîðîâ
template <typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other) {
        clear();
        for (Node* current = other.m_head->next; current != other.m_tail; current = current->next) {
            append(current->value);
        }
    }
    return *this;
}

template <typename T>
T& List<T>::operator[](size_t index) {
    if (index >= static_cast<size_t>(m_size)) throw std::out_of_range("Index out of range");
    Node* current = m_head->next;

    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->value;
}

template <typename T>
bool List<T>::operator==(const List& other) const {
    if (m_size != other.m_size) {
        return false;
    }

    Node* thisCurrent = m_head->next;
    Node* otherCurrent = other.m_head->next;

    while (thisCurrent != m_tail && otherCurrent != other.m_tail) {
        if (thisCurrent->value != otherCurrent->value) {
            return false;
        }

        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }

    return true;
}

template <typename T>
bool List<T>::operator!=(const List& other) const {
    return !(*this == other);
}

template <typename T>
List<T> List<T>::operator+(const List& other) const {
    List result(*this);

    for (Node* current = other.m_head->next; current != other.m_tail; current = current->next) {
        result.append(current->value);
    }

    return result;
}

template <typename T>
List<T>& List<T>::operator+=(const List& other) {
    for (Node* current = other.m_head->next; current != other.m_tail; current = current->next) {
        append(current->value);
    }

    return *this;
}

// Âñòàâêà ïîñëå êëþ÷à
template <typename T>
void List<T>::push_after(const T& key, const T& value) {
    Node* current = m_head;
    while (current != nullptr) {
        if (current->value == key) {
            Node* newNode = new Node(value, current->next, current);
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            else {
                m_tail = newNode; // åñëè âñòàâëÿåì â êîíåö, îáíîâëÿåì m_tail
            }
            current->next = newNode;
            m_size++;
            return;
        }
        current = current->next;
    }
    throw std::runtime_error("Key not found");
}

// Óäàëåíèå èç ãîëîâû
template <typename T>
void List<T>::remove_head() {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }

    Iterator it(m_head);
    remove(it);
}

template <typename T>
void List<T>::remove_tail() {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }

    Iterator it(m_tail);
    remove(it);
}
