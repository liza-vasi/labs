
#include <iostream>

#include <conio.h> //
#include "List.h"

int main() {
    List<int> myList;

    myList.append(10);
    myList.append(20);
    myList.append(30);

    std::cout << "Содержимое списка: ";
    myList.print();

    _getch();
    return 0;
}