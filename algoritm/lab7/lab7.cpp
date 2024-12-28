#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>
#include "../../OOP/BoolMatrix/BoolMatrix.h"
#include "../../OOP/BoolVector/BoolVector.h"

void topologicalSortUtil(int v, const BoolMatrix& graph, std::vector<bool>& visited, std::stack<int>& stack) {
    visited[v] = true;

    for (size_t neighbor = 0; neighbor < graph.getCols(); ++neighbor) {

        if (graph[v][neighbor] && !visited[neighbor]) {
            topologicalSortUtil(neighbor, graph, visited, stack);
        }
        else if (graph[v][neighbor] && visited[neighbor]) {
            throw std::invalid_argument("Цикл получается");
        }
    }

    stack.push(v);
}


std::vector<int> topologicalSort(const BoolMatrix& graph) {
    std::stack<int> stack;
    std::vector<bool> visited(graph.getRows(), false);

    for (int i = 0; i < graph.getRows(); ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, graph, visited, stack);
        }
    }

    std::vector<int> sortedOrder;
    while (!stack.empty()) {
        sortedOrder.push_back(stack.top());
        stack.pop();
    }

    return sortedOrder;
}

int main() {
    setlocale(LC_ALL, "Russian");
    BoolMatrix graph(6, 6);
    graph.setAll(false);

    graph.setValue(5, 2, true);
    graph.setValue(5, 0, true);
    graph.setValue(4, 0, true);
    graph.setValue(4, 1, true);
    graph.setValue(2, 3, true);
    graph.setValue(3, 1, true);

    std::vector<int> sortedOrder = topologicalSort(graph);

    std::cout << "Топологическая сортировка: ";
    for (int v : sortedOrder) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}

