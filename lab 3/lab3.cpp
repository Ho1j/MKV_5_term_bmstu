#include <iostream>
#include <string>
using namespace std;

// Проверка уникальности цифр в числе
bool hasDistinctDigits(const string& number) {
    for (size_t i = 0; i < number.size(); ++i) {
        for (size_t j = i + 1; j < number.size(); ++j) {
            if (number[i] == number[j]) {
                return false; // Цифры не уникальны
            }
        }
    }
    return true; // Все цифры уникальны
}

// Проверка, что большинство разрядов числа <= j
bool isValidNumber(const string& number, int j) {
    int countLessOrEqualJ = 0;
    int totalDigits = number.size();

    for (char digit : number) {
        if ((digit - '0') <= j) { // Если цифра <= j
            countLessOrEqualJ++;
        }
    }

    // Большинство разрядов: более половины разрядов <= j
    return countLessOrEqualJ > totalDigits / 2;
}

// Вывод чисел, которые удовлетворяют условиям
void listNumbers(int m, int j) {
    int start = 1;              // Начальное число для m-разрядных (минимальное натуральное)
    for (int i = 1; i < m; ++i) {
        start *= 10;            // 10^(m-1)
    }
    int end = start * 10 - 1;   // Конечное число для m-разрядных

    for (int i = start; i <= end; ++i) {
        string number = to_string(i);
        if (hasDistinctDigits(number) && isValidNumber(number, j)) {
            cout << number << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    int m = 3; // Количество разрядов
    int j = 5; // Максимальное значение для большинства разрядов

    // Обработка аргументов командной строки
    if (argc > 1) {
        m = atoi(argv[1]); // Первый аргумент: количество разрядов
    }
    if (argc > 2) {
        j = atoi(argv[2]); // Второй аргумент: максимальное значение большинства разрядов
    }

    // Проверка допустимости значений
    if (m < 1) {
        cerr << "Error: m >= 1." << endl;
        return 1;
    }
    if (j < 1 || j > 9) {
        cerr << "Error: j from 1 to 9." << endl;
        return 1;
    }

    cout << "m = " << m << endl; 
    cout << "j = " << j << endl;

    // Вывод результатов
    cout << endl << "Results:" << endl;
    listNumbers(m, j);

    return 0;
}
