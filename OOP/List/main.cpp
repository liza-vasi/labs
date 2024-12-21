#include <iostream>
#include "List.h" 

void testList() {
    List<int> list;

    list.append(10);
    list.append(20);
    list.append(30);
    std::cout << "Добавление 10, 20, 30: ";
    list.print();

    list.push_head(5);
    list.push_tail(40);
    std::cout << "Вставка 5 в голову и 40 в хвост: ";
    list.print();

    list.remove_head();
    list.remove_tail();
    std::cout << "Удаление головы и хвоста: ";
    list.print();

    list.push_after(20, 25);
    std::cout << "Вставка 25 после 20: ";
    list.print();

    list.remove(25);
    std::cout << "Удаление 25: ";
    list.print();

    std::cout << "Размер списка: " << list.size() << std::endl;

    std::cout << "Минимальное значение: " << list.min() << std::endl;
    std::cout << "Максимальное значение: " << list.max() << std::endl;

    list.clear();
    std::cout << "После очистки списка: ";
    list.print();

    std::cout << "Список пустой? ";
    if (list.isEmpty()) {
        std::cout << "Да" << std::endl;
    }
    else {
        std::cout << "Нет" << std::endl;
    }

    List<int> list1 = list; 
    list1.append(100);
    list1.append(200);

    std::cout << "Добавление во второй список 100 и 200: ";
    list1.print();

    List<int> list2 = list + list1; 
    std::cout << "Объединенный список: ";
    list2.print();
    if (list == list1) {
        std::cout << "Списки равны." << std::endl;
    }
    else {
        std::cout << "Списки не равны." << std::endl;
    }
}

int main() {
    testList();
    return 0;
}
