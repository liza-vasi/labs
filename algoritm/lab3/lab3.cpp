#include  <iostream> 
#include  <conio.h> 
#include  <vector> 
#include <ctime> 

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    int gap = n / 2; 

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2; 
    }
}

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
void randMas1(std::vector<int>& matr, int n) {
    matr.resize(n);
    for (int i = 0; i < n; i++) {
        matr[i] = std::rand() % 21 - 10; 
    }
}
void randMas2(std::vector<int>& matr, int n) {
    matr.resize(n);
    for (int i = 0; i < n; i++) {
        matr[i] = std::rand() % 2001 - 1000;
    }
}
void randMas3(std::vector<int>& matr, int n) {
    matr.resize(n);
    for (int i = 0; i < n; i++) {
        matr[i] = std::rand() % 200001 - 100000;
    }
}
int main() {
    srand(static_cast<unsigned int>(time(0)));
    setlocale(LC_ALL, "Russian");
    // Исходный массив
    int n;
    std::vector<int> array;
    for (int i = 0, n = 10000;i < 3;i++, n = n * 10) {
        randMas1(array, n);
        std::cout << "\n"<< "Количество элементов " << n << "\n";
        std::cout << "Диапазон от -10 до 10" << "\n";;
        unsigned int start_time = clock(); // начальное время
        shellSort(array);
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time;
        std::cout << "Время работы (в миллисекундах) " << search_time << "\n";

        if (isSorted(array)) {
            std::cout << "Массив отсортирован корректно." << '\n' << '\n';
        }
        else {
            std::cout << "Массив не отсортирован." << '\n' << '\n';
        }
    }
    _getch();
    return 0;
}