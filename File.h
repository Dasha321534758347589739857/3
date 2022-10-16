#pragma once
#include "Algoritm.h"
#include "Check.h"
#include <string>
double** InputDataFileInput(int& n, int& m);// функция ввода масива из файла
void InputDataFileOutput(double** matrix, int n, int m);//сохранение введённого значения в файл
void FileOutput(std::vector<std::shared_ptr<ISort>>& sorts, int n, int m, double*** matrixs);//сохранение данных в файл