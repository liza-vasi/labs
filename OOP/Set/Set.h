#pragma once
#include <iostream>
#include <string>
#include "..\BoolVector\BoolVector.h"

class Set : public BoolVector { 
public:
    static const int MIN_CHAR = 33; // Минимальный символ 
    static const int MAX_CHAR = 127; // Максимальный символ 
    static const int CHAR_RANGE = MAX_CHAR - MIN_CHAR; // Диапазон символов 

    Set(); // Конструктор по умолчанию
    Set(const char* chars);
    Set(const BoolVector& other);
    Set(const Set& other); // Конструктор копирования
    ~Set(); // Деструктор

    bool contains(char c) const; // Проверка наличия элемента в множестве;
    char min() const; // поиск максимального/минимального элемента множества;
    char max() const; // поиск максимального/минимального элемента множества;
    int size() const; // получение мощности множества;

    Set& operator=(const Set& other); // Оператор присваивания
    bool operator==(const Set& other) const; // сравнение на равенство
    bool operator!=(const Set& other) const; //  сравнение на неравенство
    Set operator|(const Set& other) const; // побитовое или
    Set& operator|=(const Set& other); //  присваивание побитового или
    Set operator&(const Set& other) const; //  побитовое и
    Set& operator&=(const Set& other); //  присваивание побитового И
    Set operator~() const; // инверсия 

    friend std::ostream& operator<<(std::ostream& os, const Set& cs); // вывод
    friend std::istream& operator>>(std::istream& is, Set& cs); //ввод
    
private:
    BoolVector boolVector;
    void m_add(const char ch);
    void m_remove(const char ch);
};