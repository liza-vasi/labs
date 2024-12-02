#include <iostream>
#include <conio.h>
#include "BoolMatrix.h"

int main() {
    
    BoolMatrix matrix(3, 3);

    // ��������� �������� � �������
    matrix.setValue(0, 0, true);
    matrix.setValue(0, 1, false);
    matrix.setValue(0, 2, true);

    matrix.setValue(1, 0, false);
    matrix.setValue(1, 1, true);
    matrix.setValue(1, 2, false);

    matrix.setValue(2, 0, true);
    matrix.setValue(2, 1, true);
    matrix.setValue(2, 2, false);

    std::cout << "�������� �������:\n" << matrix << std::endl;

    matrix.invert(1, 1); // ����������� ������� � ������ 1, ������� 1

    std::cout << "������� ����� �������� �������� (1, 1):\n" << matrix << std::endl;

    matrix.invertRange(2, 0, 2); // ����������� �������� � ������ 2 � �������� 0 � 1

    std::cout << "������� ����� �������� ��������� (2, 0) �� 2 ��������:\n" << matrix << std::endl;

    size_t weightRow1 = matrix.rowWeight(1);
    std::cout << "��� 1-� ������: " << weightRow1 << std::endl;

    BoolVector conjunctionResult = matrix.conjunction();
    std::cout << "���������� ���� �����: " << conjunctionResult << std::endl;

    BoolVector disjunctionResult = matrix.disjunction();
    std::cout << "���������� ���� �����: " << disjunctionResult << std::endl;

    _getch();
    return 0;
}