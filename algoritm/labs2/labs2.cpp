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
/*   

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[80], p[40];
    int TAB[256] = { 0 };
    int j, i, m, n,fl=1,k;
    puts("vvoni stroky");
    fgets(s,80,stdin);
    puts("vvodi obraz");
    fgets(p,40,stdin);
    n = strlen(s)-1; m = strlen(p)-1;
    //printf("n = % d, m = % d\n", n, m);
    for (i = 0; i < 256; i++) {
        TAB[i] = m;
    }
    for (i = 0; i < m - 1; i++)
        TAB[p[i]] = m - 1 - i;
    i = m - 1;
    j = m - 1;
    while (i < n) {
        k = i;
        j = m - 1;
       while (j >= 0) {

            if (s[k] == p[j]) {
                k--;
                j--;
            }
            else {
                i = k + TAB[s[k]];
                break;
            }
        }
       if (j < 0) {
           fl = 0;
           break;
       }
    }
    if (fl==1) puts("NO");//net vhogdenia
    else {
        puts("YES"); printf("index %d ", k+1);
    }//est vhogdenie
    _getch();
    return 0;
*/