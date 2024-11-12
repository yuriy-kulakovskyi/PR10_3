#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

void Print(Product* a, int N);
void AddProduct(Product* &a, int &N);
void RemoveNegativeQuantity(Product* &a, int &N);
void EditProduct(Product* a, int N);
void SortByStore(Product* a, int N);
void ReadFromFile(Product* &a, int &N);
void WriteToFile(Product* a, int N);
void Menu();

#endif
