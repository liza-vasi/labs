#include <iostream>
#include "Array.h"
#include <conio.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Количество элементов массива: ";
    std::cin >> n;
    Array arr(n);

    std::cout << "Массив: "<<'\n';
    arr.input();   
    arr.output();  

    Array arr1(arr);
    std::cout << "копирование: ";
    arr1.output();

    arr.bubleSort(); 
    std::cout << "Сортировка: ";
    arr.output(); 

    int valueInsert;
    std::cout << "Элемент, который хотите вставить: ";
    std::cin >> valueInsert;
    int indexInsert;
    std::cout << "Индекс, по которому будет элемент: ";
    std::cin >> indexInsert;
    arr.insert(indexInsert, valueInsert);
    std::cout << "Вставка: ";
    arr.output();

    int valueToFind;
    std::cout << "Элемент, который хотите найти: ";
    std::cin >> valueToFind;
    int index = arr.find(valueToFind);

    if (index != -1)
        std::cout << "Элемент " << valueToFind << " найден на индексе: " << index << '\n';
    else std::cout << "Элемент " << valueToFind << " не найден " << '\n';

    int value;
    std::cout << "Элемент, который хотите удалить: ";
    std::cin >> value;
    arr.deleteByValue(value); 
    arr.output(); 

    int allValue;
    std::cout << "Элементы, все вхождения которого хотите удалить: ";
    std::cin >> allValue;
    arr.deleteAll(allValue); 
    arr.output(); 

    std::cout << "Максимальный элемент: " << arr.max() <<'\n';
    std::cout << "Минимальный элемент: " << arr.min() <<'\n';


    std::cout << "Сравнение массивов: ";
    if (arr != arr1) {
        std::cout <<"Массивы не равны "<<'\n';
    }
    if (arr == arr1) {
        std::cout << "Массивы равны " << '\n';
    }

    std::cout << "Размер массива: ";
    std::cout << arr.getSize()<< '\n';

    int* first = arr.begin();
    int* last = arr.end();
    int valueIterator;
    std::cout << "Элемент, который хотите вставить: ";
    std::cin >> valueIterator;
    int iterator;
    std::cout << "Итератор: ";
    std::cin >> iterator;
    first += iterator;
    arr.insertBefore(first,valueIterator);
    arr.output();

    std::cout << "удаление по итератору" << "\n";
    arr.deleteByIterator(first);
    arr.output();

    int iterator1, iterator2;
    std::cout << "Начало интервала: ";
    std::cin >> iterator1;
    std::cout << "Конец интервала: ";
    std::cin >> iterator2;
    first = arr.begin()+ iterator1;
    last = arr.begin() + iterator2;

    std::cout << "удаление по итератору в интервале" << "\n";
    arr.deleteInterval(first, last);
    arr.output();

    _getch();
    return 0;
    }


