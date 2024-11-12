#include <iostream>
#include <iomanip>

#include "../include/functions.h"

using namespace std;

int main() {
    Product* products = nullptr;
    int N = 0;
    int choice;

    do {
        Menu();
        cout << "Оберіть пункт меню: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Print(products, N);
            break;
            case 2:
                AddProduct(products, N);
            break;
            case 3:
                RemoveNegativeQuantity(products, N);
            break;
            case 4:
                EditProduct(products, N);
            break;
            case 5:
                SortByStore(products, N);
            break;
            case 6:
                ReadFromFile(products, N);
            break;
            case 7:
                WriteToFile(products, N);
            break;
            case 8:
                cout << "Вихід з програми.\n";
            break;
            default:
                cout << "Неправильний вибір! Спробуйте ще раз.\n";
        }
    } while (choice != 8);

    delete[] products;
    return 0;
}
