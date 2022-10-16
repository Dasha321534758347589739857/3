#include <iostream>
#include<vector>
#include"Algoritm.h"
#include"PersonalInterface.h"
#include "Check.h"
#include"ISort.h"
#include "File.h"
#include <memory>                  //Библиотека для умных указателей
#include <string>
#include <conio.h>                 //Библиотека для _getch()
#define QUIT 27                    //Присваивание Esc значение 27
enum YesOrNo                       //Выборка для меню
{
	yes = 1,
	no = 2,
};

int main(void) {
	setlocale(LC_CTYPE, "RU");
	const int manual_input = 1;                
	const int random_input = 2;
	const int file_input = 3;
	const int sorts_count = 5;
	int n=0;                        //Размер столбцов
	int m=0;                        //Размер строчек
	int UserChoice = 0;

	std::vector <std::shared_ptr<ISort>> sorts;  //Вектор умных указателей на класс с сортировками
	sorts.emplace_back(std::make_shared <QuickSortMat>()); //Заполнение вектора указателем на класс QuickSortMat
	sorts.emplace_back(std::make_shared <BubbleSort>());
	sorts.emplace_back(std::make_shared <ShellSort>());
	sorts.emplace_back(std::make_shared <SelectionSort>());
	sorts.emplace_back(std::make_shared <InsertionSort>());
	do {

		ShowGreetings(); //Приветствие
		Showtask(); //Задание
		ShowInputChoice(); //Выбор ввода
		UserChoice = Get3Choise(); //выборка на 3 варианта
		double***  Matrix = nullptr;
		


		switch (UserChoice)
		{
		case  (manual_input):
			ShowMenuPoint(&n, &m); // ввод строк и столбцов
			Matrix = new double** [sorts_count]; //выделение памяти 
			for (int j = 0; j < sorts_count; j++) 
			{
				Matrix[j] = new double* [n];
				for (int i = 0; i < n; i++) {
					Matrix[j][i] = new double[m];
				}
			}
			 std::cout << "Введите данные" << std::endl;
			 ConsoleInput(Matrix[0], n, m); 
			 break;
		case random_input:
			ShowMenuPoint(&n, &m);// ввод строк и столбцов
			Matrix = new double** [sorts_count]; // выделение памяти
			for (int j = 0; j < sorts_count; j++)
			{
				Matrix[j] = new double* [n];
				for (int i = 0; i < n; i++) {
					Matrix[j][i] = new double[m];
				}
			}
				RandomInput(Matrix[0], n, m);
				break;
		case (file_input):
			Matrix = new double** [sorts_count];
			Matrix[0] = InputDataFileInput(n, m);
			for (int j = 1; j < sorts_count; j++)
			{
				Matrix[j] = new double* [n];
				for (int i = 0; i < n; i++) {
					Matrix[j][i] = new double[m];
				}
			}
			break;
		}
		std::cout << "Исходная матрица" << std::endl;
		ConsoleOutput(Matrix[0], n, m);
		if (UserChoice == manual_input || UserChoice == random_input) {
			ShowInputOutType(); //запрос на сохранение данных в файл
			UserChoice = GetChoise(); // выборка из 2 вариантов
			if (UserChoice == yes) {
				InputDataFileOutput(Matrix[0], n, m);  // файловый вывод введёных данных
			}
		}
		for (int i = 1; i < sorts_count; i++) // копируем значение одной матрицы в несколько других файлов
		{	
			memcpy(Matrix[i], Matrix[0], sizeof(Matrix[i]) * n);
		}

		for (int i = 0; i < sorts_count; i++) //каждую матрицу сортируем
		{
			Matrix[i] = sorts[i]->Sort(Matrix[i], n, m);
		}
		ShowResult(sorts, n, m, Matrix); // выводим результирующие матрицы и сравнительную таблицу
		ShowOutputType(); //запрос на сохранение даных в файл
		UserChoice = GetChoise(); // выборка из 2-ух
		if (UserChoice == yes) {
			FileOutput(sorts, n, m , Matrix); //сохранение данных
		}
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		for (int i = 0; i < sorts_count ; i++)
			for(int j = 0; j < n;j++)
				delete[]Matrix[i][j];
		for (int i = 0; i < sorts_count; i++)
			delete[]Matrix[i];
		delete[] Matrix;
		Matrix = nullptr;
		UserChoice = _getch();  //Получаем от пользователя символ из косоли, не отображая его
	} while (UserChoice != QUIT);

	return 0;
}
