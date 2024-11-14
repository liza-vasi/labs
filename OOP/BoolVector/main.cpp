#include "BoolVector.h"
#include <iostream>
#include <conio.h>
int main() {
    BoolVector bv(16);

    bv.setBit(0, true);
    bv.setBit(1, true);
    bv.setBit(2, false);
    bv.setBit(3, true);

    std::cout << "Начальный BoolVector: " << bv << std::endl;

    bv.invertBit(2);
    std::cout << "После инверсии бита 2: " << bv << std::endl;

    bv.setBits(4, 4, true); 
    std::cout << "После установки битов с 4 по 7 в true: " << bv << std::endl;

    std::cout << "Вес BoolVector: " << bv.weight() << std::endl;

    BoolVector bv2(16);
    bv2.setAll(true);
    std::cout << "Второй BoolVector (все биты установлены в true): " << bv2 << std::endl;

    BoolVector andResult = bv & bv2;
    std::cout << "Результат операции AND: " << andResult << std::endl;

    BoolVector orResult = bv | bv2;
    std::cout << "Результат операции OR: " << orResult << std::endl;

    BoolVector xorResult = bv ^ bv2;
    std::cout << "Результат операции XOR: " << xorResult << std::endl;

    // Сдвиг влево
    BoolVector leftShifted = bv << 1;
    std::cout << "Сдвинутый влево BoolVector: " << leftShifted << std::endl;

    // Сдвиг вправо
    BoolVector rightShifted = bv >> 1;
    std::cout << "Сдвинутый вправо BoolVector: " << rightShifted << std::endl;

	_getch();
	return 0;
}
