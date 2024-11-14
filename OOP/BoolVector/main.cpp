#include "BoolVector.h"
#include <iostream>
#include <conio.h>
int main() {
    BoolVector bv(16);

    bv.setBit(0, true);
    bv.setBit(1, true);
    bv.setBit(2, false);
    bv.setBit(3, true);

    std::cout << "��������� BoolVector: " << bv << std::endl;

    bv.invertBit(2);
    std::cout << "����� �������� ���� 2: " << bv << std::endl;

    bv.setBits(4, 4, true); 
    std::cout << "����� ��������� ����� � 4 �� 7 � true: " << bv << std::endl;

    std::cout << "��� BoolVector: " << bv.weight() << std::endl;

    BoolVector bv2(16);
    bv2.setAll(true);
    std::cout << "������ BoolVector (��� ���� ����������� � true): " << bv2 << std::endl;

    BoolVector andResult = bv & bv2;
    std::cout << "��������� �������� AND: " << andResult << std::endl;

    BoolVector orResult = bv | bv2;
    std::cout << "��������� �������� OR: " << orResult << std::endl;

    BoolVector xorResult = bv ^ bv2;
    std::cout << "��������� �������� XOR: " << xorResult << std::endl;

    // ����� �����
    BoolVector leftShifted = bv << 1;
    std::cout << "��������� ����� BoolVector: " << leftShifted << std::endl;

    // ����� ������
    BoolVector rightShifted = bv >> 1;
    std::cout << "��������� ������ BoolVector: " << rightShifted << std::endl;

	_getch();
	return 0;
}
