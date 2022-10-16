#pragma once
#include "Check.h"
#include "ISort.h"
#include <iomanip> //библиотека для setw(внешность выведенного массива)
#include <ctime> //для рандомного ввода
void ConsoleInput(double** matrix, int n, int m);
void RandomInput(double** matrix, int n, int m);
void copy(double** a, double** b, int n, int m);
template <class T> void swap(T& a, T& b) //шаблон для сортировок, меняет местами числа
{
	T c(a); a = b; b = c;
}
void ConsoleOutput(double** matrix, int n, int m); // вывод введённой матрицы на экран

void ShowResult(std::vector <std::shared_ptr<ISort>>& sorts, int n, int m, double*** matrixs); //результирующие матрицы и таблица