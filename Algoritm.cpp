#include "Algoritm.h"

void ConsoleInput(double** matrix, int n, int m) 
{
	for (int i = 0; i <n ; i++)
	{
		for (int j = 0; j < m; j++) {
			
			std::cout << "matrix[" << i+1 << "][" << j+1<< "]="  << std::endl;
			matrix[i][j] = GetDouble();  // проверка на даблы
			std::cout << "" << std::endl;
		}
	}
}

void RandomInput(double** matrix, int n, int m)
{
	const int lower_bound=-25;
	const int higher_bound=50;
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			matrix[i][j] = lower_bound + rand() % (higher_bound + 1) + rand() / (RAND_MAX + 1.0);
		}
	}

}

void copy(double** a, double** b, int n, int m) //копирование данных из одной матрицы в другую
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = b[i][j];
}

void ConsoleOutput(double** matrix, int n, int m) //выводим введённую матрицу
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			std::cout << std::setw(10) << matrix[i][j]<<" ";
		std::cout << std::endl;
	}
}



void ShowResult(std::vector <std::shared_ptr<ISort>>& sorts , int n, int m , double*** matrixs) //функция для вывода результата
{
	for (int index = 0; index < 5; index++) {
		std::cout << "Название метода сортировки: " << sorts[index]->GetName() << std::endl;
		std::cout << "Колличество сравнений: " << sorts[index]-> GetComparison() << std::endl;
		std::cout << "Колличество перестановок: " << sorts[index]->GetPermutation() << std::endl;
		std::cout << "Результирующая матрица: " << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				std::cout << std::setw(10) << matrixs[index][i][j] << " ";
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Название метода сортировки       сравнения        перестановоки" << std::endl;
	for (int index = 0; index < 5; index++) { //таблица результатов
		if (sorts[index]->GetName() == "SelectionSort" || sorts[index]->GetName() == "InsertionSort") {
			std::cout << sorts[index]->GetName() << "                        " << sorts[index]->GetComparison() << "                  " << sorts[index]->GetPermutation() << std::endl;
		}
		else if(sorts[index]->GetName() == "BubbleSort") {
			std::cout << sorts[index]->GetName() << "                           " << sorts[index]->GetComparison() << "                  " << sorts[index]->GetPermutation() << std::endl;
		}
		else {
			std::cout << sorts[index]->GetName() << "                             " << sorts[index]->GetComparison() << "                 " << sorts[index]->GetPermutation() << std::endl;
		}
	}
	
}

