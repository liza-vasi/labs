#include <iostream>
#include "Array.h"
#include <conio.h>
int main() {
        setlocale(LC_ALL, "Russian");
        Array<int> arr;

        std::cout << "Введите 5 элементов для массива: ";
        for (int i = 0; i < 5; ++i) {
            int value;
            std::cin >> value;
            arr.addInEnd(value);
        }

        std::cout << "Элементы массива: ";
        arr.output();

        arr.bubbleSort();
        std::cout << "Отсортированный массив: ";
        arr.output();

        std::cout << "Максимальный элемент: " << arr.max() << std::endl;
        std::cout << "Минимальный элемент: " << arr.min() << std::endl;

        int indexToDelete;
        std::cout << "Введите индекс элемента для удаления: ";
        std::cin >> indexToDelete;
        if (arr.deleteByIndex(indexToDelete)) {
            std::cout << "Элемент удален. Обновленный массив: ";
            arr.output();
        }
        else {
            std::cout << "Ошибка: индекс выходит за пределы массива." << std::endl;
        }

        int valueToDelete;
        std::cout << "Введите значение для удаления всех вхождений: ";
        std::cin >> valueToDelete;
        arr.deleteAll(valueToDelete);
        std::cout << "Массив после удаления всех вхождений значения " << valueToDelete << ": ";
        arr.output();
    _getch();
    return 0;
}
