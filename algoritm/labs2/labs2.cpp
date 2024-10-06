#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
//  получения индексов всех вхождений подстроки в заданном диапазоне
std::vector<int> BM(const std::string& line, const std::string& image, int start, int end, int number) {
    std::vector<int> indices; // вектор для хранения индексов вхождений
    int Size_i = image.length();

    // проверка на корректность входных параметров
    if (start < 0 || end >= line.length() || start > end || Size_i == 0) {
        return indices; // возвращаем пустой вектор 
    }

    std::vector<int> TAB(256, Size_i); // инициализируем таблицу

    for (int i = 0; i < Size_i - 1; i++) {
        TAB[image[i]] = Size_i - 1 - i; // заполняем таблицу
    }
    for (int i = start; i <= end - Size_i + 1;) {
        int j = Size_i - 1;

        while (j >= 0 && line[i + j] == image[j]) {
            j--;
        }

        if (j < 0) { // если образ найден
            indices.push_back(i); // сохраняем индекс вхождения
            if (number == 1) {
                return indices;
                break;
            }
            i += Size_i; // смещаем на длину образа для поиска следующих вхождений
        }
        else {
            int charValue = line[i + j];
            int shift = (charValue < 256) ? TAB[charValue] : Size_i;
            i += std::max(1, j - shift); // смещение

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
    int Size_l = line.length();
    std::vector<int> index = BM(line, image, 0, Size_l-1, 1);
    
    std::cout << "Индекс первого вхождения: ";
    for (int x : index) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // поиск всех вхождений в заданном диапазоне
    int start;
    int end;

    std::cout << "Диапазон вхождений: ";
    std::cin >> start;
    std::cin >> end;
    std::vector<int> occurrences = BM(line, image, start, end,-1);
    std::cout << "Индексы всех вхождений: ";
    for (int x : occurrences) {
        std::cout << x << " ";
    }

    _getch();
    return 0;
}
