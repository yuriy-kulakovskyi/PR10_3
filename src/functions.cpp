#include "../include/functions.h"
#include "../include/structures.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

void Menu() {
    cout << "\n=== МЕНЮ ===\n";
    cout << "1. Вивести список товарів\n";
    cout << "2. Додати новий товар\n";
    cout << "3. Видалити товари з від'ємною кількістю\n";
    cout << "4. Редагувати товар\n";
    cout << "5. Сортувати товари за назвою магазину\n";
    cout << "6. Зчитати дані з файлу\n";
    cout << "7. Записати дані у файл\n";
    cout << "8. Вихід\n";
}

void Print(Product* a, int N) {
    cout << "\n=== Список товарів ===\n";
    for (int i = 0; i < N; i++) {
        cout << "Назва товару: " << a[i].name
             << ", Магазин: " << a[i].store
             << ", Вартість: " << a[i].price
             << ", Кількість: " << a[i].quantity
             << ", Одиниця вимірювання: " << a[i].unit << endl;
    }
}

void AddProduct(Product* &a, int &N) {
    Product* temp = new Product[N + 1];
    for (int i = 0; i < N; i++)
        temp[i] = a[i];

    cout << "\n=== Додавання нового товару ===\n";
    cout << "Назва товару: "; cin >> temp[N].name;
    cout << "Назва магазину: "; cin >> temp[N].store;
    cout << "Вартість товару: "; cin >> temp[N].price;
    cout << "Кількість товару: "; cin >> temp[N].quantity;
    cout << "Одиниця вимірювання: "; cin >> temp[N].unit;

    delete[] a;
    a = temp;
    N++;
}

void RemoveNegativeQuantity(Product* &a, int &N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (a[i].quantity >= 0) count++;
    }

    Product* temp = new Product[count];
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (a[i].quantity >= 0) {
            temp[j++] = a[i];
        }
    }

    delete[] a;
    a = temp;
    N = count;
}

void EditProduct(Product* a, int N) {
    string productName;
    cout << "\nВведіть назву товару для редагування: ";
    cin >> productName;

    for (int i = 0; i < N; i++) {
        if (a[i].name == productName) {
            cout << "Нова вартість: "; cin >> a[i].price;
            cout << "Нова кількість: "; cin >> a[i].quantity;
            return;
        }
    }
    cout << "Товар не знайдено.\n";
}

void SortByStore(Product* a, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j].store > a[j + 1].store) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void ReadFromFile(Product* &a, int &N) {
    string filename;
    cout << "Введіть ім'я файлу для читання: ";
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не вдалося відкрити файл.\n";
        return;
    }

    file >> N;
    delete[] a;
    a = new Product[N];

    for (int i = 0; i < N; i++) {
        file >> a[i].name >> a[i].store >> a[i].price >> a[i].quantity >> a[i].unit;
    }

    file.close();
    cout << "Дані успішно завантажені з файлу.\n";
}

void WriteToFile(Product* a, int N) {
    string filename;
    cout << "Введіть ім'я файлу для запису: ";
    cin >> filename;
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не вдалося відкрити файл для запису.\n";
        return;
    }

    file << N << endl;
    for (int i = 0; i < N; i++) {
        file << a[i].name << " " << a[i].store << " " << a[i].price
             << " " << a[i].quantity << " " << a[i].unit << endl;
    }

    file.close();
    cout << "Дані успішно записані у файл.\n";
}