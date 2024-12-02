#include <iostream>
#include <conio.h>
#include "BoolMatrix.h"

int main() {
    
    BoolMatrix matrix(3, 3);

    // Установка значений в матрице
    matrix.setValue(0, 0, true);
    matrix.setValue(0, 1, false);
    matrix.setValue(0, 2, true);

    matrix.setValue(1, 0, false);
    matrix.setValue(1, 1, true);
    matrix.setValue(1, 2, false);

    matrix.setValue(2, 0, true);
    matrix.setValue(2, 1, true);
    matrix.setValue(2, 2, false);

    std::cout << "Исходная матрица:\n" << matrix << std::endl;

    matrix.invert(1, 1); // Инвертируем элемент в строке 1, столбце 1

    std::cout << "Матрица после инверсии элемента (1, 1):\n" << matrix << std::endl;

    matrix.invertRange(2, 0, 2); // Инвертируем элементы в строке 2 с индексов 0 и 1

    std::cout << "Матрица после инверсии диапазона (2, 0) на 2 элемента:\n" << matrix << std::endl;

    size_t weightRow1 = matrix.rowWeight(1);
    std::cout << "Вес 1-й строки: " << weightRow1 << std::endl;

    BoolVector conjunctionResult = matrix.conjunction();
    std::cout << "Конъюнкция всех строк: " << conjunctionResult << std::endl;

    BoolVector disjunctionResult = matrix.disjunction();
    std::cout << "Дизъюнкция всех строк: " << disjunctionResult << std::endl;

    _getch();
    return 0;
}