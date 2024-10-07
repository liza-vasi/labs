#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
std::vector<int> BM(const std::string& text, const std::string& image, int start, int end, bool firstOrAll) {
    std::vector<int> indices; 
    int imageSize = image.length();

    if (start < 0 || end >= text.length() || start > end || imageSize == 0) {
        return indices; 
    }

    std::vector<int> shiftTable(256, imageSize); 

    for (int i = 0; i < imageSize - 1; i++) {
        shiftTable[image[i]] = imageSize - 1 - i; 
    }
    for (int i = start; i <= end - imageSize + 1;) {
        int j = imageSize - 1;

        while (j >= 0 && text[i + j] == image[j]) {
            j--;
        }

        if (j < 0) { 
            indices.push_back(i); 
            if (firstOrAll) {
                break;
            }
            i += imageSize; 
        }
        else {
            //char charValue = text[i + j];
            int shift = shiftTable[text[i + j]];

            i += std::max(1, j - shift); 
        }
    }

    return indices; 
}


int main() {
    setlocale(LC_ALL, "Russian");
    std::string text, image;
    std::cout << "Введите строку: ";
    std::getline(std::cin, text);
    std::cout << "Введите образ: ";
    std::getline(std::cin, image);
    int textSize = text.length();
    std::vector<int> index = BM(text, image, 0, textSize -1, 1);
    
    std::cout << "Индекс первого вхождения: ";
    for (int x : index) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    int start;
    int end;

    std::cout << "Диапазон вхождений: ";
    std::cin >> start;
    std::cin >> end;
    std::vector<int> occurrences = BM(text, image, start, end,0);
    std::cout << "Индексы всех вхождений: ";
    for (int x : occurrences) {
        std::cout << x << " ";
    }

    _getch();
    return 0;
}
