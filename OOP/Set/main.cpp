#include "Set.h"
#include <conio.h>
#include <iostream>
int main() {

    Set setA("22.12.2024");
    Set setB("23.12.2024");

    std::cout << "��������� A: " << setA << std::endl;
    std::cout << "��������� B: " << setB << std::endl;

    char checkChar = 'P';
    if (setA.contains(checkChar)) {
        std::cout << "��������� A �������� '" << checkChar << "': ��" << std::endl;
    }
    else {
        std::cout << "��������� A �������� '" << checkChar << "': ���" << std::endl;
    }

    Set unionSet = setA | setB;
    std::cout << "����������� �������� A � B: " << unionSet << std::endl;

    Set Set111 = setA / setB;
    std::cout << "�������� �������� A � B: " << Set111 << std::endl;

    Set intersectionSet = setA & setB;
    std::cout << "����������� �������� A � B: " << intersectionSet << std::endl;

    Set invertedSet = ~setA;
    std::cout << "��������������� ��������� A: " << invertedSet << std::endl;

    if (setA == setB) {
        std::cout << "��������� A ����� ��������� B: ��" << std::endl;
    }
    else {
        std::cout << "��������� A ����� ��������� B: ���" << std::endl;
    }

    Set userSet;
    std::cout << "������� ��������� ��������: ";
    std::cin >> userSet;
    std::cout << "�� ���������: " << userSet << std::endl;




    //_getch();
    return 0;
}