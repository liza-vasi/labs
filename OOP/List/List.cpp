#include "List.h"

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
    return end(); // Если не найдено, возвращаем end()
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
    if (pos.m_node == m_head || pos.m_node == m_tail) {
        return; // Нельзя удалять фиктивные узлы
    }
    Node* toDelete = pos.m_node;

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
            break; // Удаляем только первое вхождение
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
    clear(); // Очищаем текущий список

    for (const auto& value : values) {
        append(value); // Заполняем отсортированными значениями
    }
}

// Перегрузка операторов
template <typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other) { // Проверка на самоприсваивание
        clear(); // Очищаем текущий список
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

    return true; // Все элементы совпадают
}

template <typename T>
bool List<T>::operator!=(const List& other) const {
    return !(*this == other);
}

template <typename T>
List<T> List<T>::operator+(const List& other) const {
    List result(*this); // Создаем копию текущего списка

    for (Node* current = other.m_head->next; current != other.m_tail; current = current->next) {
        result.append(current->value); // Добавляем элементы из другого списка
    }

    return result;
}

template <typename T>
List<T>& List<T>::operator+=(const List& other) {
    for (Node* current = other.m_head->next; current != other.m_tail; current = current->next) {
        append(current->value); // Добавляем элементы из другого списка
    }

    return *this;
}

