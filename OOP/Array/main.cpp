#include <iostream>
#include "Array.h"
#include <conio.h>
int main() {
        setlocale(LC_ALL, "Russian");
        Array<int> arr;

        std::cout << "������� 5 ��������� ��� �������: ";
        for (int i = 0; i < 5; ++i) {
            int value;
            std::cin >> value;
            arr.addInEnd(value);
        }

        std::cout << "�������� �������: ";
        arr.output();

        arr.bubbleSort();
        std::cout << "��������������� ������: ";
        arr.output();

        std::cout << "������������ �������: " << arr.max() << std::endl;
        std::cout << "����������� �������: " << arr.min() << std::endl;

        int indexToDelete;
        std::cout << "������� ������ �������� ��� ��������: ";
        std::cin >> indexToDelete;
        if (arr.deleteByIndex(indexToDelete)) {
            std::cout << "������� ������. ����������� ������: ";
            arr.output();
        }
        else {
            std::cout << "������: ������ ������� �� ������� �������." << std::endl;
        }

        int valueToDelete;
        std::cout << "������� �������� ��� �������� ���� ���������: ";
        std::cin >> valueToDelete;
        arr.deleteAll(valueToDelete);
        std::cout << "������ ����� �������� ���� ��������� �������� " << valueToDelete << ": ";
        arr.output();
    _getch();
    return 0;
}
