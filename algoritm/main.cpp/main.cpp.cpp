
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib> 
#include <ctime> 
#include <conio.h>
#include <cmath>
void OutPutMatr(const std::vector<std::vector<int>>& matr) {
    int razmer1 = matr.size();
    if (razmer1 == 0) { return; } // поверка на пустую матрицу
    int razmer2 = matr[0].size();

    for (int i = 0; i < razmer1; ++i) {
        for (int j = 0; j < razmer2; ++j) {
            std::cout << matr[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void RandMas(std::vector<std::vector<int>>& matr, int n) {
    std::srand(static_cast<unsigned int>(std::time(0))); // инициализация генератора случайных чисел
    //matr.resize(n, std::vector<int>(n)); // инициализация матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matr[i][j] = 0; 
            }
            else {
                matr[i][j] =std :: rand() % 10 + 1; 
            }
        }
    }
}

int enumeration(const std::vector<std::vector<int>>& matr,  std::vector<bool>& visit, int nachalo, int n, int count, int cost, int otvet, int& maximum, std::vector<int>& path, std::vector<int>& bestPath, bool debug = false) 
     {
    path.push_back(nachalo); // Добавляем текущий город в путь

    // если все города посещены, возвращаемся в начальный город
    
    if (count == n && matr[nachalo][0]) {// matr[nachalo][0] проверка на то, можем ли мы вернуться 
        cost += matr[nachalo][0];
        if (debug)
        {
            for (int city : path) {
                std::cout << city+1 << " ";
            }
            std::cout << '\n';
        }
        if  (cost >maximum) {
            maximum = cost;
        }
        if (cost < otvet) {
            otvet = cost;
            bestPath = path; // Сохраняем лучший путь
            //put.push_back(1); // добавляем начальный город в конец пути
        }
    }
    // Перебор всех городов
    for (int city = 0; city < n; city++) {
        if (!visit[city] && matr[nachalo][city]) {  
            visit[city] = true; // помечаем город как посещенны
            //put.push_back(city+1); // Добавляем город в путь
            otvet = enumeration(matr, visit, city, n, count + 1, cost + matr[nachalo][city], otvet, maximum, path, bestPath, debug);
            visit[city] = false;
            // возвращаемся к предыдущему состоянию
        }
    }
    path.pop_back();
    return otvet;
}

// функция для нахождения ближайшего города
int MinDistanceCity(int nowCity, const std::vector<std::vector<int>>& matr,  std ::vector<bool>& visit) {
    int novisitcity = -1;
    int mindistance = std:: numeric_limits<int>::max();

    for (int i = 0; i < matr.size(); i++) {
        if (!visit[i] && matr[nowCity][i] < mindistance) {
            mindistance = matr[nowCity][i];
            novisitcity = i;
        }
    }

    return novisitcity;
}

// жадный алгоритм 
int GreedyAlgoritm(const std::vector<std::vector<int>>& matr, std::vector<int>& path) {
    int n = matr.size();
     std::vector<bool> visit(n, false);
    visit[0] = true; // начинаем с первого города
    path.push_back(0); // добавляем начальный город в путь
    int city = 0;// типа индекс текущего города
    int line = 0;

    for (int i = 1; i < n; i++) {
        int nextCity = MinDistanceCity(city, matr, visit);
        if (nextCity == -1) {
            break;
        } 
        line += matr[city][nextCity];
        visit[nextCity] = true;
        path.push_back(nextCity); // добавляем следующий город в путь
        city = nextCity;
    }
    // возвращаемся в исходный город
    line += matr[city][0];
    return line;
}

int main() {
  
    setlocale(LC_ALL, "Russian");
    int n,i=0;
    for (n = 4;n <= 9;n = n + 2) {
        for (int i = 0;i < 3;i++) {
            //cout << "Введите количество городов: ";
            //cin >> n;
            std::vector< std::vector<int>> matr(n, std::vector<int>(n));// выделена память под н элементов, которе проиннициализированы векторами размера н
            // вектор содержит векторы, которые содержат целые числа
            RandMas(matr, n);

            std::cout << "\n\nСгенерированная матрица расстояний:" << '\n';
            OutPutMatr(matr);
            int nachalo = 0;
            std::vector<bool> visit(n, false);//массив который отслеживает, какие города уже были посещены. 
            visit[nachalo] = true; // Начинаем с первого города
            std::cout << "Метод перебора" << '\n';
            int maximum = -1;
            std::vector<int> path; // текущий путь
            std::vector<int> bestPath; // лучший найденный путь
            unsigned int start_time = clock(); // начальное время
            int otvet = enumeration(matr, visit, nachalo, n, 1, 0, std::numeric_limits<int>::max(), maximum, path, bestPath, false);
            unsigned int end_time = clock(); // конечное время
            unsigned int search_time = end_time - start_time;
            std::cout << "Время работы (в миллисекундах) " << search_time << "\n";
            std::cout << "Макисмально плохой путь " << maximum << '\n';
            if (otvet == std::numeric_limits<int>::max()) {
                std::cout << "Нет возможного пути." << "\n";
            }
            else {
                std::cout << "Общая длина пути: " << otvet << '\n';
                std::cout << "Лучший путь: ";
                for (int city : bestPath) {
                    std::cout << city+1 << " ";
                }
                std::cout << '\n';
            }
            std::cout << '\n';
            std::cout << "Жадный алгоритм" << '\n';
            std::vector<int> greedyPath; // Путь жадного алгоритма
            start_time = clock(); // начальное время
            int line = GreedyAlgoritm(matr, greedyPath);
            end_time = clock(); // конечное время
            search_time = end_time - start_time;
            std::cout << "Время работы (в миллисекундах) " << search_time << '\n';
            std::cout << "Общая длина пути: " << line << '\n';
            std::cout << "Путь жадного алгоритма: ";
            for (int city : greedyPath) {
                std::cout << city+1 << " ";
            }
            std::cout << '\n';
            float percent = abs(100 - ((100*line - 100*otvet) / (maximum - otvet)));
            std::cout << "процент качества решения "<<percent << "%" << '\n';
        }
    }
    _getch();
    return 0;
}