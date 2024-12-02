#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include <cmath>

// Функция для проверки, отсортирован ли массив
bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}/*Алгоритм побитовой сортировки
Вызов l = 0, r = n – 1, k = номер старшего разряда.
1. Если l ≥ r или k < 0, то выход.
2. Установка начальных значений: i = l, j = r.
3. Пока i ≤ j
3.1 Пока i ≤ j и в k-ом разряде A[i] ноль, i++;
3.2 Пока i ≤ j и в k-ом разряде A[j] единица, j--.
3.3 Если i < j , то A[i] ↔ A[j], i ++, j --.
4. Выполняем эту же процедуру для фрагмента [l, j] по
k-1 разряду.
5. Выполняем эту же процедуру для фрагмента [i, r] по
k-1 разряду.*/

void bitSort(std::vector<int>& arr,int l, int r, int k) {
    int n = arr.size();
    
    if (l >= r || k < 0) {
        return;
    }
    int i = l;
    int j = r;
    while (i <= j) {
        while (i <= j && (arr[i] & (1 << k)) == 0) {
            i++;
        }
        while (i <= j && (arr[i] & (1 << k)) == 1) {
            j--;
        }
        if (i < j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }

    }
    bitSort(arr,l,j,k-1);
    bitSort(arr,i,r,k-1);

}
int maxBitLength(const std::vector<int>& arr){
    int k = 0;//номер старшего разряда(как найти то?)  Можно через фор найти размер в двоичной записи самого большого числа
    for (int i = 0;i < arr.size();i++) {
        if (log2(arr[i]) > k)
            k = log2(arr[i]);
    }
    return k;
}

std::vector<int> readArrayFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> arr;
    int value;

    if (file.is_open()) {
        while (file >> value) {
            arr.push_back(value);
        }
        file.close();
        std::cout << "  Считано элементов: " << arr.size() << " из файла " << filename << std::endl;
    }
    else {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    }

    return arr;
}

int main()
{
    
        setlocale(LC_ALL, "Russian");
        const std::vector<std::string> filenames = {
            "исходный_массив_10000_-10_10.txt",
            "исходный_массив_10000_-1000_1000.txt",
            "исходный_массив_10000_-100000_100000.txt",
            "исходный_массив_100000_-10_10.txt",
            "исходный_массив_100000_-1000_1000.txt",
            "исходный_массив_100000_-100000_100000.txt",
            "исходный_массив_1000000_-10_10.txt",
            "исходный_массив_1000000_-1000_1000.txt",
            "исходный_массив_1000000_-100000_100000.txt"
        };
        for (int i = 0; i < 3; i++) {
            std::cout << i + 1 << '.';
            for (const auto& filename : filenames) {
                auto arr = readArrayFromFile(filename);

                if (arr.empty()) {
                    std::cerr << "Ошибка: массив пуст!" << std::endl;

                }

                auto start_time = std::chrono::high_resolution_clock::now();
                bitSort(arr,0, arr.size() - 1, maxBitLength(arr));
                auto end_time = std::chrono::high_resolution_clock::now();

                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
                std::cout << "  Время работы (в миллисекундах): " << duration << "\n";

                if (!isSorted(arr)) {
                    std::cerr << "Ошибка: массив не отсортирован!" << std::endl;
                }
                else {
                    std::cout << "  Массив успешно отсортирован." << std::endl;
                }
            }
        }

        return 0;
    }



