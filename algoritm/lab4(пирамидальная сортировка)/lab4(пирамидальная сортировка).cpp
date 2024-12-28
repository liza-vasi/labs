#include <iostream>
#include <vector>
#include <conio.h>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>

bool isSorted(const std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Функция для пирамидальной сортировки
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем корень как самый большой элемент
    int left = 2 * i + 1; // левый = 2*i + 1
    int right = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый дочерний элемент больше самого большого элемента на данный момент
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если самый большой элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]); // меняем местами

        // Рекурсивно хипифицируем затронутое поддерево
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]); // Перемещаем текущий корень в конец
        heapify(arr, i, 0); // вызываем хипификацию на уменьшенной куче
    }
}

// Функция для чтения массива из файла
std::vector<int> readArrayFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> arr;
    int value;

    if (file.is_open()) {
        while (file >> value) {
            arr.push_back(value);
        }
        file.close();
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
        std::vector<long long> durations;

        for (int i = 0; i < 3; i++) {
            auto arr = readArrayFromFile(filename);

            if (arr.empty()) {
                std::cerr << "Ошибка: массив пуст!" << std::endl;

            }

            auto start_time = std::chrono::high_resolution_clock::now();
            heapSort(arr);
            auto end_time = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            std::cout << "  Время работы (в миллисекундах): " << duration << "\n";
            durations.push_back(duration);
            if (!isSorted(arr)) {
                std::cerr << "Ошибка: массив не отсортирован!" << std::endl;
            }
            else {
                std::cout << "  Массив успешно отсортирован." << std::endl;
            }
        }

        long long average_duration = std::accumulate(durations.begin(), durations.end(), 0LL) / durations.size();
        std::cout << "  Среднее время работы для файла '" << filename << "' (в миллисекундах): " << average_duration << "\n";
    }
    _getch();
    return 0;
}