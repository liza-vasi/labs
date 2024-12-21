#include <iostream>
#include "List.h" 

void testList() {
    List<int> list;

    list.append(10);
    list.append(20);
    list.append(30);
    std::cout << "���������� 10, 20, 30: ";
    list.print();

    list.push_head(5);
    list.push_tail(40);
    std::cout << "������� 5 � ������ � 40 � �����: ";
    list.print();

    list.remove_head();
    list.remove_tail();
    std::cout << "�������� ������ � ������: ";
    list.print();

    list.push_after(20, 25);
    std::cout << "������� 25 ����� 20: ";
    list.print();

    list.remove(25);
    std::cout << "�������� 25: ";
    list.print();

    std::cout << "������ ������: " << list.size() << std::endl;

    std::cout << "����������� ��������: " << list.min() << std::endl;
    std::cout << "������������ ��������: " << list.max() << std::endl;

    list.clear();
    std::cout << "����� ������� ������: ";
    list.print();

    std::cout << "������ ������? ";
    if (list.isEmpty()) {
        std::cout << "��" << std::endl;
    }
    else {
        std::cout << "���" << std::endl;
    }

    List<int> list1 = list; 
    list1.append(100);
    list1.append(200);

    std::cout << "���������� �� ������ ������ 100 � 200: ";
    list1.print();

    List<int> list2 = list + list1; 
    std::cout << "������������ ������: ";
    list2.print();
    if (list == list1) {
        std::cout << "������ �����." << std::endl;
    }
    else {
        std::cout << "������ �� �����." << std::endl;
    }
}

int main() {
    testList();
    return 0;
}
