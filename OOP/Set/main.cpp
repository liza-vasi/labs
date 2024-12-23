#include "Set.h"
#include <conio.h>
#include <iostream>
int main() {

    Set setA("22.12.2024");
    Set setB("23.12.2024");

    std::cout << "Множество A: " << setA << std::endl;
    std::cout << "Множество B: " << setB << std::endl;

    char checkChar = 'P';
    if (setA.contains(checkChar)) {
        std::cout << "Множество A содержит '" << checkChar << "': Да" << std::endl;
    }
    else {
        std::cout << "Множество A содержит '" << checkChar << "': Нет" << std::endl;
    }

    Set unionSet = setA | setB;
    std::cout << "Объединение множеств A и B: " << unionSet << std::endl;

    Set Set111 = setA / setB;
    std::cout << "Разность множеств A и B: " << Set111 << std::endl;

    Set intersectionSet = setA & setB;
    std::cout << "Пересечение множеств A и B: " << intersectionSet << std::endl;

    Set invertedSet = ~setA;
    std::cout << "Инвертированное множество A: " << invertedSet << std::endl;

    if (setA == setB) {
        std::cout << "Множество A равно множеству B: Да" << std::endl;
    }
    else {
        std::cout << "Множество A равно множеству B: Нет" << std::endl;
    }

    Set userSet;
    std::cout << "Введите множество символов: ";
    std::cin >> userSet;
    std::cout << "Моё множество: " << userSet << std::endl;




    //_getch();
    return 0;
}