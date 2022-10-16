#include "PersonalInterface.h"


void ShowGreetings()
{
	std::cout << "Контрольная работа №3 Новая Дарья 415г" << std::endl;
}


void ShowInputChoice()
{
	std::cout << "Как ввод данных хотитие использовать?" << std::endl;
	std::cout << "1)Консольный" << std::endl;
	std::cout << "2)Случайными числами" << std::endl;
	std::cout << "3)Файловый" << std::endl;
}
void ShowInputOutType()
{
	std::cout << "Вы хотите сохранить исходные данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	
}
void ShowOutputChoise()
{
	std::cout << "Вы хотите перезаписать данный фаил?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Ввести новое имя(путь к фаилу)" << std::endl;
}
void ShowOutputType() {
	std::cout << "Вы хотите записать данные в фаил?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
}

void Showtask()
{
	std::cout << "Упорядочить каждую строку матрицы по возрастанию отрицательных величин." << std::endl;
}

void ShowMenuPoint(int* n,int* m)
{
	std::cout << "Введите размерность матрицы(n на m):" << std::endl;
	std::cout << "n=";
	*n = GetPositiveInt();
	std::cout << "m="; *m = GetPositiveInt();
}
