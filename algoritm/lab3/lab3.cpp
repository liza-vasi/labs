#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <string>
#include <conio.h>
#include <cmath>

void shellSort(std::vector<int>& arr, int gap) {
    int n = arr.size();
    for (int i = gap; i < n; i++) {
        int temp = arr[i];
        int j;
        for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
            arr[j] = arr[j - gap];
        }
        arr[j] = temp;
    }
}

void shellSortWithHibbardGaps(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> gaps;
    
    for (int m = 1; pow(2, m) - 1 < n; m++) {
        gaps.push_back(pow(2, m) - 1); // 2^m - 1
    }

    for (int i = gaps.size() - 1; i >= 0; i--) {
        shellSort(arr, gaps[i]);
    }
}

void shellSortWithKnuthGaps(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> gaps;
    for (int gap = 1; gap < n; gap = 3 * gap + 1) {
        gaps.push_back(gap);
    }
    for (int i = gaps.size() - 1; i >= 0; i--) {
        shellSort(arr, gaps[i]);
    }
}

void shellSortWithSedgwickGaps(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> gaps;
    for (int m = 0; ; m++) {
        int gap;

        if (m % 2 == 0) {
            gap = 9 * (1 * pow(2, m / 2)) - 9; 
        }
        else {
            gap = 8 * (1 * pow(2, (m + 1) / 2)) - 6;
        }

        if (gap >= n) break;
        gaps.push_back(gap);
    }
    for (int i = gaps.size() - 1; i >= 0; i--) {
        shellSort(arr, gaps[i]);
    }
}

bool isSorted(const std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

std::vector<int> generateRandomArray(int size, int minValue, int maxValue) {
    std::vector<int> arr(size);

    
    std::random_device rd; // получаем случайное число от устройства
    std::mt19937 gen(rd()); // инициализация генератора
    std::uniform_int_distribution<> dis(minValue, maxValue); // определяем распределение

    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen); // генерируем числа в диапазоне [minValue, maxValue]
    }

    return arr;
}

void saveArrayToFile(const std::vector<int>& arr, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int num : arr) {
            file << num << "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Не удалось открыть файл для записи: " << filename << "\n";
    }
}


void writeArrayToFile(const std::vector<int>& arr, const std::string& filename) {
    std::ofstream outFile(filename);
    for (int i = 0; i < arr.size(); i++) {
        outFile << arr[i] << "\n";
    }
}



int main() {
    setlocale(LC_ALL, "Russian");
    const std::vector<int> sizes = { 10000, 100000, 1000000 };
    const std::vector<std::pair<int, int>> ranges = { {-10, 10}, {-1000, 1000}, {-100000, 100000} };

    for (int i = 0; i < sizes.size(); ++i) {
        int size = sizes[i];
        for (int j = 0; j < ranges.size(); ++j) {
            std::pair<int, int> range = ranges[j];
            std::vector<int> arrHibbard = generateRandomArray(size, range.first, range.second);
            std::vector<int> arrKnuth = arrHibbard;
            std::vector<int> arrSedgwick = arrHibbard;

            // Сохраняем исходные массивы в файл
            std::string filename = "исходный_массив_" + std::to_string(size) + "_" + std::to_string(range.first) + "_" + std::to_string(range.second) + ".txt";
            saveArrayToFile(arrHibbard, filename);

            unsigned int start_time1 = clock(); // начальное время
            shellSortWithHibbardGaps(arrHibbard);
            unsigned int end_time1 = clock(); // конечное время
            int timeHibbard = (end_time1 - start_time1) ; // в миллисекундах
            std::cout << "Время работы Хиббард (в миллисекундах): " << timeHibbard << "\n";

            unsigned int start_time2 = clock(); // начальное время
            shellSortWithKnuthGaps(arrKnuth);
            unsigned int end_time2 = clock(); // конечное время
            int timeKnuth = (end_time2 - start_time2) ; 
            std::cout << "Время работы Кнут (в миллисекундах): " << timeKnuth << "\n";

            unsigned int start_time3 = clock(); // начальное время
            shellSortWithSedgwickGaps(arrSedgwick);
            unsigned int end_time3 = clock(); // конечное время
            int timeSedgwick = (end_time3 - start_time3) ; // в миллисекундах
            std::cout << "Время работы Седвик (в миллисекундах): " << timeSedgwick << "\n";

            
            std::cout << '\n';
        }
    }

    _getch();
    return 0;
}
