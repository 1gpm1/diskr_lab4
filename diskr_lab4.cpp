#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

void permute(std::vector<int>& array, int i, int n) {
    if (i == n) {
        for (int j = 0; j <= n; j++) {
            std::cout << array[j] << " ";
        }
        std::cout << std::endl;
    }
    else {
        for (int j = i; j <= n; j++) {
            std::swap(array[i], array[j]);
            permute(array, i + 1, n);
            std::swap(array[i], array[j]);
        }
    }
}

bool nextCombination(std::vector<int>& combination, int n, int r) {
    int i = r - 1;
    while (i >= 0 && combination[i] == n - r + i + 1) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    combination[i]++;
    for (int j = i + 1; j < r; j++) {
        combination[j] = combination[i] + j - i;
    }
    return true;
}

void printCombination(std::vector<int>& combination) {
    for (int i = 0; i < combination.size(); i++) {
        std::cout << combination[i] << " ";
    }
    std::cout << std::endl;
}

void zavd1() {
    int n;
    std::cout << "Введіть число n: ";
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }
    permute(array, 0, n - 1);
}

void zavd2() {
    int n, r;
    std::cout << "Введіть n: ";
    std::cin >> n;
    std::cout << "Введіть r (r ≤ n): ";
    std::cin >> r;
    std::vector<int> combination(r);

    // Початкове сполучення
    for (int i = 0; i < r; i++) {
        combination[i] = i + 1;
    }
    printCombination(combination);

    // Побудова лексикографічно наступного сполучення
    while (nextCombination(combination, n, r)) {
        printCombination(combination);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    std::cout << "Виберіть завдання (1 або 2): ";
    std::cin >> choice;

    if (choice == 1) {
        zavd1();
    }
    else if (choice == 2) {
        zavd2();
    }
    else {
        std::cout << "Неправильний вибір. Завершення програми." << std::endl;
    }

    return 0;
}
