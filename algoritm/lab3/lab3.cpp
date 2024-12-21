#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <string>
#include <conio.h>
#include <numeric>
#include <algorithm>
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

    for (int m = 1; ; m++) {
        int gap = pow(2, m) - 1; 
        if (gap >= n) break;
        gaps.push_back(gap);
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
        }
    }
            
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
                    std::vector<int> arrHibbard = readArrayFromFile(filename);
                    std::vector<int> arrKnuth = arrHibbard;
                    std::vector<int> arrSedgwick = arrHibbard;

                    unsigned int totalTimeHibbard = 0, totalTimeKnuth = 0, totalTimeSedgwick = 0;
                    for (int k = 0; k < 3; ++k) {
                        

                        // Измерение времени для Hibbard
                        auto startHibbard = std::chrono::high_resolution_clock::now();
                        shellSortWithHibbardGaps(arrHibbard);
                        auto endHibbard = std::chrono::high_resolution_clock::now();
                        totalTimeHibbard += std::chrono::duration_cast<std::chrono::microseconds>(endHibbard - startHibbard).count();

                        // Измерение времени для Knuth
                        auto startKnuth = std::chrono::high_resolution_clock::now();
                        shellSortWithKnuthGaps(arrKnuth);
                        auto endKnuth = std::chrono::high_resolution_clock::now();
                        totalTimeKnuth += std::chrono::duration_cast<std::chrono::microseconds>(endKnuth - startKnuth).count();

                        // Измерение времени для Sedgwick
                        auto startSedgwick = std::chrono::high_resolution_clock::now();
                        shellSortWithSedgwickGaps(arrSedgwick);
                        auto endSedgwick = std::chrono::high_resolution_clock::now();
                        totalTimeSedgwick += std::chrono::duration_cast<std::chrono::microseconds>(endSedgwick - startSedgwick).count();
                    }

                    unsigned int averageTimeHibbard = totalTimeHibbard / 3;
                    unsigned int averageTimeKnuth = totalTimeKnuth / 3;
                    unsigned int averageTimeSedgwick = totalTimeSedgwick / 3;

                    std::cout << "Файл: " << filename << "\n";
                    std::cout << "Среднее время работы Хиббард (в миллисекундах): " << averageTimeHibbard << "\n";
                    std::cout << "Среднее время работы Кнут (в миллисекундах): " << averageTimeKnuth << "\n";
                    std::cout << "Среднее время работы Сэджвик (в миллисекундах): " << averageTimeSedgwick << "\n";

                    std::cout << "\n";
                }

    _getch();
    return 0;
}
