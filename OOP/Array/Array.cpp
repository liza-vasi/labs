#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Array.h" 
template <typename T>
Array<T>::Array(int size) : m_size(size) {
    if (size <= 0) {
        throw std::invalid_argument("Размер должен быть больше нуля.");
    }
    m_array = new T[m_size];
}

template <typename T>
Array<T>::Array(const Array& other) : m_size(other.m_size) {
    m_array = new T[m_size];
    std::copy(other.m_array, other.m_array + m_size, m_array);
}

template <typename T>
Array<T>::Array(Array&& other) noexcept : m_array(other.m_array), m_size(other.m_size) {
    other.m_array = nullptr;
    other.m_size = 0;
}

template <typename T>
Array<T>::~Array() {
    delete[] m_array;
}

template <typename T>
bool Array<T>::insert(const int index, const T& value) {
    if (index < 0 || index >= m_size) {
        return false;
    }
    m_array[index] = value;
    return true;
}

template <typename T>
void Array<T>::swap(Array& other) noexcept {
    std::swap(m_array, other.m_array);
    std::swap(m_size, other.m_size);
}

template <typename T>
int Array<T>::getSize() const {
    return m_size;
}

template <typename T>
void Array<T>::input() {
    for (int i = 0; i < m_size; ++i) {
        std::cout << "Введите элемент " << i << ": ";
        std::cin >> m_array[i];
    }
}

template <typename T>
void Array<T>::output() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int Array<T>::find(const T& value) const {
    for (int i = 0; i < m_size; ++i) {
        if (m_array[i] == value) {
            return i;
        }
    }
    return -1; // Не найдено
}

template <typename T>
void Array<T>::bubbleSort() {
    for (int i = 0; i < m_size - 1; ++i) {
        for (int j = 0; j < m_size - i - 1; ++j) {
            if (m_array[j] > m_array[j + 1]) {
                std::swap(m_array[j], m_array[j + 1]);
            }
        }
    }
}

template <typename T>
bool Array<T>::deleteByIndex(int index) {
    if (index < 0 || index >= m_size) {
        return false;
    }
    for (int i = index; i < m_size - 1; ++i) {
        m_array[i] = m_array[i + 1];
    }
    --m_size;
    return true;
}

template <typename T>
bool Array<T>::deleteByValue(const T& value) {
    int index = find(value);
    return deleteByIndex(index);
}

template <typename T>
void Array<T>::deleteAll(const T& value) {
    for (int i = 0; i < m_size;) {
        if (m_array[i] == value) {
            deleteByIndex(i);
        }
        else {
            ++i;
        }
    }
}

template <typename T>
T Array<T>::max() const {
    if (m_size == 0) throw std::runtime_error("Массив пуст.");
    return *std::max_element(m_array, m_array + m_size);
}

template <typename T>
T Array<T>::min() const {
    if (m_size == 0) throw std::runtime_error("Массив пуст.");
    return *std::min_element(m_array, m_array + m_size);
}

template <typename T>
T* Array<T>::begin() {
    return m_array;
}

template <typename T>
const T* Array<T>::begin() const {
    return m_array;
}

template <typename T>
T* Array<T>::end() {
    return m_array + m_size;
}

template <typename T>
const T* Array<T>::end() const {
    return m_array + m_size;
}

template <typename T>
void Array<T>::addInEnd(const T& value) {
    T* newArray = new T[m_size + 1];
    std::copy(m_array, m_array + m_size, newArray);
    newArray[m_size] = value;
    delete[] m_array;
    m_array = newArray;
    ++m_size;
}

template <typename T>
void Array<T>::insertBefore(T* iterator, const T& value) {
    if (iterator < m_array || iterator >= m_array + m_size) {
        throw std::out_of_range("Итератор выходит за пределы массива.");
    }
    T* newArray = new T[m_size + 1];
    std::copy(m_array, iterator, newArray);
    newArray[iterator - m_array] = value;
    std::copy(iterator, m_array + m_size, newArray + (iterator - m_array + 1));
    delete[] m_array;
    m_array = newArray;
    ++m_size;
}

template <typename T>
void Array<T>::deleteByIterator(T* iterator) {
    if (iterator < m_array || iterator >= m_array + m_size) {
        throw std::out_of_range("Итератор выходит за пределы массива.");
    }
    int index = iterator - m_array;
    T* newArray = new T[m_size - 1];
    std::copy(m_array, m_array + index, newArray);
    std::copy(m_array + index + 1, m_array + m_size, newArray + index);
    delete[] m_array;
    m_array = newArray;
    --m_size;
}

template <typename T>
bool Array<T>::deleteInterval(T* begin, T* end) {
    if (begin < m_array || end >= m_array + m_size || begin > end) {
        throw std::out_of_range("Указанные итераторы выходят за пределы массива.");
    }
    int countToDelete = end - begin + 1;
    T* newArray = new T[m_size - countToDelete];
    std::copy(m_array, begin, newArray);
    std::copy(end + 1, m_array + m_size, newArray + (begin - m_array));
    delete[] m_array;
    m_array = newArray;
    m_size -= countToDelete;

    return true;
}

template <typename T>
bool Array<T>::operator!=(const Array& other) const {
    if (m_size != other.m_size) return true;
    for (int i = 0; i < m_size; ++i) {
        if (m_array[i] != other.m_array[i]) return true;
    }
    return false;
}

template <typename T>
bool Array<T>::operator==(const Array& other) const {
    return !(*this != other);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] m_array;
        m_size = other.m_size;
        m_array = new T[m_size];
        std::copy(other.m_array, other.m_array + m_size, m_array);
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] m_array;
        m_array = other.m_array;
        m_size = other.m_size;
        other.m_array = nullptr;
        other.m_size = 0;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= m_size) throw std::out_of_range("Индекс выходит за пределы массива.");
    return m_array[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= m_size) throw std::out_of_range("Индекс выходит за пределы массива.");
    return m_array[index];
}

template <typename T>
Array<T> Array<T>::operator+(const Array& other) const {
    Array result(m_size + other.m_size);
    std::copy(m_array, m_array + m_size, result.m_array);
    std::copy(other.m_array, other.m_array + other.m_size, result.m_array + m_size);
    return result;
}

template <typename T>
Array<T>& Array<T>::operator+=(const Array& other) {
    *this = *this + other;
    return *this;
}
