#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
#include <conio.h>

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Функция побитовой сортировки
void bitSort(std::vector<int>& arr, int l, int r, int k) {
    if (l >= r || k < 0) {
        return;
    }

    int i = l;
    int j = r;

    // Разделение по текущему биту
    while (i <= j) {
        while (i <= j && ((arr[i] >> k) & 1) == 0) {
            i++;
        }
        while (i <= j && ((arr[j] >> k) & 1) == 1) {
            j--;
        }
        if (i < j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    bitSort(arr, l, j, k - 1);
    bitSort(arr, i, r, k - 1);
}

void sortArray(std::vector<int>& arr) {
    if (arr.empty()) return;

    int k = sizeof(int) * 8 - 1; // Максимальный бит для 32-битного целого числа
    bitSort(arr, 0, arr.size() - 1, k);
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
        std::cout << "Считано элементов: " << arr.size() << " из файла " << filename << std::endl;
    }
    else {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    }

    return arr;
}

int main() {
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

    for (const auto& filename : filenames) {
        auto arr = readArrayFromFile(filename);

        if (arr.empty()) {
            std::cerr << "Ошибка: массив пуст!" << std::endl;
            continue;
        }

        auto start_time = std::chrono::high_resolution_clock::now();
        sortArray(arr);
        auto end_time = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        std::cout << "Время работы (в миллисекундах): " << duration << "\n";

        if (isSorted(arr)) {
            std::cerr << "Ошибка: массив не отсортирован!" << std::endl;
        }
        else {
            std::cout << "Массив успешно отсортирован." << std::endl;
        }
    }
    _getch();
    return 0;
}
