#include <iostream>
#include <Windows.h>
using namespace std;

const int M = 20, N = 20; // максимальна кількість рядків та стовпців

void task1();
void task2();
void get_matr(int matr[M][N], int& m, int& n);
int find_max_row_sum(const int matr[M][N], int m, int n, int& max_row);
void remove_positive_col(int matr[M][N], int& m, int& n);
void print_matr(const int matr[M][N], int m, int n);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    do {
        cout << "Номер завдання -> ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Вихід..." << endl;
            break;
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        default:
            cout << "Неправильний номер завдання!" << endl;
        }
    } while (choice != 0);
}

// Функція введення матриці
void get_matr(int matr[M][N], int& m, int& n) {
    do {
        cout << "Введіть кількість рядків (2-20): ";
        cin >> m;
        cout << "Введіть кількість стовпців (2-20): ";
        cin >> n;
    } while (n < 2 || n > N || m < 2 || m > M);

    cout << "Введіть елементи: " << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matr[i][j];
}

// Функція пошуку рядка з максимальною сумою елементів
int find_max_row_sum(const int matr[M][N], int m, int n, int& max_row) {
    int max_sum = 0;
    for (int i = 0; i < m; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++)
            row_sum += matr[i][j];
        if (row_sum > max_sum) {
            max_sum = row_sum;
            max_row = i;
        }
    }
    return max_sum;
}

// Функція видалення першого стовпця з додатніми елементами
void remove_positive_col(int matr[M][N], int& m, int& n) {
    bool found = false;
    for (int j = 0; j < n; j++) {
        bool all_positive = true;
        for (int i = 0; i < m; i++) {
            if (matr[i][j] <= 0) {
                all_positive = false;
                break;
            }
        }
        if (all_positive) {
            found = true;
            for (int i = 0; i < m; i++) {
                for (int k = j + 1; k < n; k++) {
                    matr[i][k - 1] = matr[i][k];
                }
            }
            n--;
            break;
        }
    }
    if (!found)
        cout << "Не знайдено стовпців з додатніми елементами." << endl;
}

// Функція виведення матриці
void print_matr(const int matr[M][N], int m, int n) {
    cout << endl << "Матриця: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << matr[i][j] << "\t";
        cout << endl;
    }
}

// Функція виконання завдання 1
void task1() {
    int matr[M][N];
    int m, n;
    get_matr(matr, m, n);
    print_matr(matr, m, n);

    int max_row;
    int max_sum = find_max_row_sum(matr, m, n, max_row);
    cout << "Рядок з максимальною сумою: " << max_row + 1 << ", сума: " << max_sum << endl;

}

// Функція виконання завдання 2
void task2() {
    int matr[M][N];
    int m, n;
    get_matr(matr, m, n);
    print_matr(matr, m, n);

    remove_positive_col(matr, m, n);
    print_matr(matr, m, n);
  
}
