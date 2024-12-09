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
 
size_t findKBit(std::vector<int>& arr) { 
    int maxValue = *std::max_element(arr.begin(), arr.end()); 
    size_t k = 0; 
 
    while (maxValue > 0) { 
        maxValue >>= 1; 
        k++; 
    } 
 
    return k - 1; 
} 
 
void bitSort(std::vector<int>& arr, int k=31, int l, int r, bool sortBySetBit) { 
    if (l >= r || k < 0) 
        return; 
 
    int i = l, j = r; 
    while (i <= j) { 
         
            while (i <= j && ((arr[i] >>k)&1)==sortBySetBit)
                i++; 
             while (i <= j && ((arr[i] >>k)&1)==!sortBySetBit)
                j--; 
            if (i < j) { 
                std::swap(arr[i], arr[j]); 
                i++; 
                j--; 
            } 
        
        
    } 
 
    bitSort(arr, k - 1, l, j, sortBySetBit); 
    bitSort(arr, k - 1, i, r, sortBySetBit); 
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
        bitSort(arr, 31, 0, arr.size() - 1, 1);  
        auto end_time = std::chrono::high_resolution_clock::now();       
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count(); 
        std::cout << "Время работы (в миллисекундах): " << duration << "\n"; 
 
        if (!isSorted(arr)) { 
            std::cerr << "Ошибка: массив не отсортирован!" << std::endl; 
        } 
        else { 
            std::cout << "Массив успешно отсортирован." << std::endl; 
        } 
    } 
 
    _getch(); 
    return 0; 
}
