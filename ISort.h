#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include "NegativeNunb.h"

class ISort //базовый класс дл€ всех сортировок
{
protected:
	std::string name; // название сортировки
	int comparison_counter = 0; //количество сравнений
	int permutation_counter = 0; // количество перестановок
public:
	virtual double** Sort(double** Matrix,int n,int m) = 0; //создаЄм метод Sort, virtual-  определ€ет в начале программы, а не во врем€ компил€ции, какую реализацию использовать
	~ISort()=default; //деструктор 
	std::string GetName(); 
	int GetComparison();
	int GetPermutation();
};
class BubbleSort :public ISort {
public:
	double** Sort(double** Matrix, int n, int m) override;  //переопредел€ем виртуальную функцию
};
class SelectionSort :public ISort {

public:
	double** Sort(double** Matrix, int n, int m)override;

};
class InsertionSort :public ISort {

public:
	double** Sort(double** Matrix, int n, int m)override;
};
class ShellSort :public ISort {
public:
	double** Sort(double** Matrix, int n, int m)override;
};
class QuickSortMat :public ISort {
private:
	void QuickSort(std::vector <NegativeNunb>& arr, int start, int end);
	int Partition(std::vector <NegativeNunb>&  arr, int start, int end);
public:
	double**  Sort(double** Matrix, int n, int m)override;
	
};