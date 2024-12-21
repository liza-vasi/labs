#pragma once
#include <iostream>
#include <string>
#include "..\BoolVector\BoolVector.h"

class Set : public BoolVector { 
public:
    static const int MIN_CHAR = 33; // ����������� ������ 
    static const int MAX_CHAR = 127; // ������������ ������ 
    static const int CHAR_RANGE = MAX_CHAR - MIN_CHAR; // �������� �������� 

    Set(); // ����������� �� ���������
    Set(const char* chars);
    Set(const BoolVector& other);
    Set(const Set& other); // ����������� �����������
    ~Set(); // ����������

    bool contains(char c) const; // �������� ������� �������� � ���������;
    char min() const; // ����� �������������/������������ �������� ���������;
    char max() const; // ����� �������������/������������ �������� ���������;
    int size() const; // ��������� �������� ���������;

    Set& operator=(const Set& other); // �������� ������������
    bool operator==(const Set& other) const; // ��������� �� ���������
    bool operator!=(const Set& other) const; //  ��������� �� �����������
    Set operator|(const Set& other) const; // ��������� ���
    Set& operator|=(const Set& other); //  ������������ ���������� ���
    Set operator&(const Set& other) const; //  ��������� �
    Set& operator&=(const Set& other); //  ������������ ���������� �
    Set operator~() const; // �������� 

    friend std::ostream& operator<<(std::ostream& os, const Set& cs); // �����
    friend std::istream& operator>>(std::istream& is, Set& cs); //����
    
private:
    BoolVector boolVector;
    void m_add(const char ch);
    void m_remove(const char ch);
};