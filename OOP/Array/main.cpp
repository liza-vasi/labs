#include <iostream>
#include "Array.h"
#include <conio.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "���������� ��������� �������: ";
    std::cin >> n;
    Array arr(n);

    std::cout << "������: "<<'\n';
    arr.input();   
    arr.output();  

    Array arr1(arr);
    std::cout << "�����������: ";
    arr1.output();

    arr.bubleSort(); 
    std::cout << "����������: ";
    arr.output(); 

    int valueInsert;
    std::cout << "�������, ������� ������ ��������: ";
    std::cin >> valueInsert;
    int indexInsert;
    std::cout << "������, �� �������� ����� �������: ";
    std::cin >> indexInsert;
    arr.insert(indexInsert, valueInsert);
    std::cout << "�������: ";
    arr.output();

    int valueToFind;
    std::cout << "�������, ������� ������ �����: ";
    std::cin >> valueToFind;
    int index = arr.find(valueToFind);

    if (index != -1)
        std::cout << "������� " << valueToFind << " ������ �� �������: " << index << '\n';
    else std::cout << "������� " << valueToFind << " �� ������ " << '\n';

    int value;
    std::cout << "�������, ������� ������ �������: ";
    std::cin >> value;
    arr.deleteByValue(value); 
    arr.output(); 

    int allValue;
    std::cout << "��������, ��� ��������� �������� ������ �������: ";
    std::cin >> allValue;
    arr.deleteAll(allValue); 
    arr.output(); 

    std::cout << "������������ �������: " << arr.max() <<'\n';
    std::cout << "����������� �������: " << arr.min() <<'\n';


    std::cout << "��������� ��������: ";
    if (arr != arr1) {
        std::cout <<"������� �� ����� "<<'\n';
    }
    if (arr == arr1) {
        std::cout << "������� ����� " << '\n';
    }

    std::cout << "������ �������: ";
    std::cout << arr.getSize()<< '\n';

    int* first = arr.begin();
    int* last = arr.end();
    int valueIterator;
    std::cout << "�������, ������� ������ ��������: ";
    std::cin >> valueIterator;
    int iterator;
    std::cout << "��������: ";
    std::cin >> iterator;
    first += iterator;
    arr.insertBefore(first,valueIterator);
    arr.output();

    std::cout << "�������� �� ���������" << "\n";
    arr.deleteByIterator(first);
    arr.output();

    int iterator1, iterator2;
    std::cout << "������ ���������: ";
    std::cin >> iterator1;
    std::cout << "����� ���������: ";
    std::cin >> iterator2;
    first = arr.begin()+ iterator1;
    last = arr.begin() + iterator2;

    std::cout << "�������� �� ��������� � ���������" << "\n";
    arr.deleteInterval(first, last);
    arr.output();

    _getch();
    return 0;
    }


