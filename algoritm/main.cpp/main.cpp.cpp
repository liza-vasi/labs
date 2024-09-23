
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib> // Для rand и srand
#include <ctime> 
#include <conio.h>
using namespace std;

const int INF = numeric_limits<int>::max();//типа бесканечна многа
/*void OutPutMatr(vector<vector<int>>& matr) {//Параметр matr — это ссылка на вектор векторов целых чисел.
    //Использование ссылки (&) позволяет избежать копирования данных, что эффективно с точки зрения производительности.
    for (const auto& stroka : matr) {
        for (int chislo : stroka) {
            cout << chislo << " ";
        }
        cout << "\n";
    }
}*/
void OutPutMatr(const vector<vector<int>>& matr) {
    int razmer1 = matr.size();
    if (razmer1 == 0) { return; } // поверка на пустую матрицу
    int razmer2 = matr[0].size();

    for (int i = 0; i < razmer1; ++i) {
        for (int j = 0; j < razmer2; ++j) {
            cout << matr[i][j] << " ";
        }
        cout << "\n";
    }
}
void RandMas(vector<vector<int>>& matr, int n) {
    srand(static_cast<unsigned int>(time(0))); // инициализация генератора случайных чисел

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matr[i][j] = 0; 
            }
            else {
                matr[i][j] = rand() % 10 + 1; 
            }
        }
    }
}

int perebor(const vector<vector<int>>& matr, vector<bool>& visit, int nachalo, int n,
            int count, int cost, int otvet, bool debug = false) {
    // если все города посещены, возвращаемся в начальный город
    
    if (count == n && matr[nachalo][0]) {// matr[nachalo][0] проверка на то, можем ли мы вернуться 
        cost += matr[nachalo][0];
        if (debug)
        {
            cout << ""; // permutation + cost
        }
        if (cost < otvet) {
            otvet = cost;
            //put.push_back(1); // добавляем начальный город в конец пути
        }
        
    }
    // Перебор всех городов
    for (int city = 0; city < n; city++) {
        if (!visit[city] && matr[nachalo][city]) {  
            visit[city] = true; // помечаем город как посещенны
            //put.push_back(city+1); // Добавляем город в путь
            otvet = perebor(matr, visit, city, n, count + 1, cost + matr[nachalo][city], otvet);
            visit[city] = false;
            // возвращаемся к предыдущему состоянию
        }
    }
    return otvet;
}
int Maximum(const vector<vector<int>>& matr, vector<bool>& visit, int nachalo, int n, int count, int cost, int otvet) {
    
    if (count == n && matr[nachalo][0]) {
        if (cost + matr[nachalo][0] > otvet) {
            otvet = cost + matr[nachalo][0];
        }
        
    }
    for (int city = 0; city < n; city++) {
        if (!visit[city] && matr[nachalo][city]) {
            visit[city] = true;
            otvet = Maximum(matr, visit, city, n, count + 1, cost + matr[nachalo][city], otvet);
            visit[city] = false;
        }
    }
    return otvet;
}



// функция для нахождения ближайшего города
int MinDistanceCity(int nowCity, const vector<vector<int>>& matr,  vector<bool>& visit) {
    int novisitcity = -1;
    int mindistance = INT_MAX;

    for (int i = 0; i < matr.size(); i++) {
        if (!visit[i] && matr[nowCity][i] < mindistance) {
            mindistance = matr[nowCity][i];
            novisitcity = i;
        }
    }

    return novisitcity;
}

// жадный алгоритм 
void GreedyAlgoritm(const vector<vector<int>>& matr) {
    int n = matr.size();
    vector<bool> visit(n, false);
    visit[0] = true; // начинаем с первого города

    int city = 0;// типа индекс текущего города
    int line = 0;

    //cout << "Порядок посещения городов: 1 ";

    for (int i = 1; i < n; i++) {
        int nextCity = MinDistanceCity(city, matr, visit);
        if (nextCity == -1) {
            cout << "Нет возможного пути";
            break;
        } // если все города посещены
        //cout << nextCity+1 << " ";
        line += matr[city][nextCity];
        visit[nextCity] = true;
        city = nextCity;
    }

    // возвращаемся в исходный город
    line += matr[city][0];
    //cout << "1" << '\n'; // возвращение в начальный город

    cout << "Общая длина пути: " << line << '\n';
}

int main() {
  
    setlocale(LC_ALL, "Russian");
    int n,i=0;
    for (n = 4;n <= 9;n=n+2) {
        for (int i=0;i < 3;i++) {
            //cout << "Введите количество городов: ";
            //cin >> n;

            vector<vector<int>> matr(n, vector<int>(n));// выделена память под н элементов, которе проиннициализированы векторами размера н
            //OutPutMatr(matr);//обозначаем матрицу расстояний
            // вектор содержит векторы, которые содержат целые числа
            // матрица будет заполнена 
            RandMas(matr, n);

            cout << "\n\nСгенерированная матрица расстояний:" << '\n';
            OutPutMatr(matr);
            int nachalo = 0;
            //cout << "Начальный город: ";
            //cin >> nachalo;
            vector<bool> visit(n, false);//массив который отслеживает, какие города уже были посещены. 
            visit[nachalo] = true; // Начинаем с первого города
            cout << "Метод перебора" << '\n';
            //vector<int> put;
            //put.push_back(1); // добавляем начальный город в путь
            unsigned int start_time = clock(); // начальное время
            int otvet = perebor(matr, visit, nachalo, n, 1, 0, INF);
            unsigned int end_time = clock(); // конечное время
            unsigned int search_time = end_time - start_time;
            cout << "Время работы (в миллисекундах) " << search_time << "\n";
            int maximum= Maximum(matr, visit, nachalo, n, 1, 0, 0);
            cout << "Макисмально плохой путь " << maximum << '\n';
            if (otvet == INF) {
                cout << "Нет возможного пути." << "\n";
            }
            else {
                cout << "Общая длина пути: " << otvet << '\n';
                /* cout << "Порядок посещаемых городов: ";
                 for (int city : put) {
                     cout << city << " ";
                 }*/
                cout << '\n';
            }
            cout << "Жадный алгоритм" << '\n';

            start_time = clock(); // начальное время
            GreedyAlgoritm(matr);
            end_time = clock(); // конечное время
            search_time = end_time - start_time;
            cout << "Время работы (в миллисекундах) " << search_time<<'\n';

        }
    }
    _getch();
    return 0;
}
