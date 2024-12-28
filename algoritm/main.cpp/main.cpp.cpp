#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
//  получения индекса первого вхождения подстроки
int IndexOfOccurrence(const std::string& line, const std::string& image) {
    int Size_l = line.length(); 
    int Size_i = image.length(); 

    if (Size_i == 0) return 0; // если подстрока пустая, возвращаем 0
    if (Size_l < Size_i) return -1; // если строка короче подстроки, возвращаем -1

    std::vector<int> TAB(256, Size_i); // инициализируем таблицу

    for (int i = 0; i < Size_i - 1; i++) {
        TAB[image[i]] = Size_i - 1 - i; // заполняем таблицу
    }

    int i = Size_i - 1;

    while (i < Size_l) {
        int k = i;
        int j = Size_i - 1;

        while (j >= 0) {
            if (line[k] == image[j]) {
                k--;
                j--;
            }
            else {
                i = k + TAB[line[k]];
                break;
            }
        }

        if (j < 0) { //если это  значит образ найден
            return k + 1; // возвращаем индекс вхождения
        }
    }

    return -1; //  если вхождение не найдено
}

//  получения индексов всех вхождений подстроки в заданном диапазоне
std::vector<int> FindAllOccurrencesInRange(const std::string& line, const std::string& image, int start, int end) {
    std::vector<int> indices; // вектор для хранения индексов вхождений
    int Size_i = image.length(); 

    // проверка на корректность входных параметров
    if (start < 0 || end >= line.length() || start > end || Size_i == 0) {
        return indices; // возвращаем пустой вектор 
    }

    // цикл для перебора строки в заданном диапазоне
    for (int i = start; i <= end - Size_i + 1; ++i) {
        if (line.substr(i, Size_i) == image) { // сравниваем подстроку с искомой
            indices.push_back(i); // сохраняем индекс вхождения
        }
    }

    return indices; // возвращаем вектор с индексами всех вхождений
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string line, image;
        std::cout << "Введите строку: ";
        std::getline(std::cin, line);
        std::cout << "Введите образ: ";
        std::getline(std::cin, image);
        // поиск первого вхождения
        int index = IndexOfOccurrence(line, image);
        if (index == -1) {
            std::cout << "Нет вхождения" << '\n';
        }
        else {
            std::cout << "Индекс первого вхождения: " << index << "\n";
        }

        // поиск всех вхождений в заданном диапазоне
        int start;
        int end;

        std::cout << "Диапазон вхождений ";
        std::cin >> start;
        std::cin >> end;
        std::vector<int> occurrences = FindAllOccurrencesInRange(line, image, start, end);
        std::cout << "Индексы всех вхождений: ";
        for (int x : occurrences) {
            std::cout << x << " ";
        }
    
    _getch();
    return 0;
}
