#include "File.h"

double** InputDataFileInput(int& n, int& m) // функция ввода масива из файла
{
	std::string file_name = "";
	std::ifstream file;
	double** tmp_matrix = nullptr;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit); //добавление исключений при ошибки считывания
	while (true)
	{
		std::cout << "Введите имя фаила. " << std::endl << "Ввод : ";
		std::cin >> file_name;
		try
		{
			file.open(file_name);
			std::cout << "Фаил открыт успешно " << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "Неверное имя фаила или путь. Повторите ввод " << std::endl;
			continue;

		}
		try
		{
			std::string str;
			n = CheckLineI(file); // проверка на int
			m = CheckLineI(file);
			double** new_matrix = new double* [n]; // выделение памяти
			for (int k = 0; k < n; k++) {
				new_matrix[k] = new double[m];
			}
			for (int i = 0; i < n; i++) {
				str = CheckLineS(file); // проверка введённых строк
				std::vector<std::string> strin;
				std::string tmp_string;
				for (int j = 0; j <= static_cast<int>(str.size()); j++) {
					if ((!isdigit(str[j]) && str[j] != '.' && str[j] != '-') || str[j] == '\n') // условие окончание считывания
					{
						strin.push_back(tmp_string); // добавление строки в вектор
						tmp_string = "";
					}
					tmp_string += str[j];
				}

				for (int k = 0; k < static_cast<int>( strin.size()); k++) {
					if (strin[k] == " ") {
						strin.erase(strin.begin() + k); // удаляем последний символ из строки
					}
				}
				if (static_cast<int>(strin.size()) != m) {
					throw 1;
				}
				for (int j = 0; j < m; j++) {
					new_matrix[i][j] = stod(strin[j]); // проверяем  все введённые значения на double
				}
			}
			tmp_matrix = new_matrix;
		}
		catch (int)
		{
			file.close();
			std::cout << "В фаиле содержатся некорректные данные" << std::endl;
			continue;
		}
		file.close();
		return tmp_matrix; // возвращаем матрицу
	}
}

void InputDataFileOutput(double** matrix, int n, int m)  //сохранение введённого значения в файл
{
	const int Yes = 1;
	std::string name;
	std::ofstream FileRecorder;// открываем файл
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckExist; // закрываем файл
	CheckExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	while (true)
	{

		std::cout << "Введите имя фаила или полный путь." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "Неверный тип фаила\n" << std::endl;
			continue;
		}
		try
		{
			CheckExist.open(name);
			std::cout << "Фаил с таким именем существует. " << std::endl
				<< "1 - Перезаписать этот фаил " << std::endl
				<< "2 - Ввести новое имя фаила " << std::endl;
			int var = GetChoise();
			if (var == Yes)
			{
				FileRecorder.open(name);
				CheckExist.close();
			}
			else
			{
				CheckExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << " Ошибка сохранения " << std::endl;
				continue;
			}

		}
		break;

	}
	FileRecorder << n << std::endl; // записываем в файл
	FileRecorder << m << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			FileRecorder << matrix[i][j] << " ";
		FileRecorder << std::endl;
	}
	FileRecorder.close();
	std::cout << "Данные успешно сохранены" << std::endl;

}

void FileOutput(std::vector < std::shared_ptr < ISort>>& sorts, int n, int m, double*** matrixs) //сохранение данных в файл
{
	const int Yes = 1;
	std::string name;
	std::ofstream FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckExist;
	CheckExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	while (true)
	{

		std::cout << "Введите имя фаила или полный путь." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "Не верный тип фаила\n" << std::endl;
			continue;
		}
		try
		{
			CheckExist.open(name);
			std::cout << "Фаил с таким именем существует. " << std::endl
				<< "1 - Перезаписать этот фаил " << std::endl
				<< "2 - Ввести новое имя фаила " << std::endl;
			int var = GetChoise();
			if (var == Yes)
			{
				FileRecorder.open(name);
				CheckExist.close();
			}
			else
			{
				CheckExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << " Ошибка сохранения "<< std::endl;
				continue;
			}

		}
		break;

	}
	FileRecorder << "Отсортированая матрица: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			FileRecorder << std::setw(10) << matrixs[0][i][j] << " ";
		FileRecorder << std::endl;
	}
	FileRecorder << std::endl;
	for (int index = 0; index < 5; index++) {
		FileRecorder << "Название метода сортировки: " << sorts[index]->GetName() << std::endl;
		FileRecorder << "Колличество сравнений: " << sorts[index]->GetComparison() << std::endl;
		FileRecorder << "Колличество сравнений: " << sorts[index]->GetPermutation() << std::endl;
	}
	FileRecorder << std::endl;
	FileRecorder << "Название метода сортировки сравнения перестановоки" << std::endl;
	for (int index = 0; index < 5; index++) {
		if (sorts[index]->GetName() == "SelectionSort" || sorts[index]->GetName() == "InsertionSort") {
			FileRecorder << sorts[index]->GetName() << " " << sorts[index]->GetComparison() << " " << sorts[index]->GetPermutation() << std::endl;
		}
		else if (sorts[index]->GetName() == "BubbleSort") {
			FileRecorder << sorts[index]->GetName() <<" " << sorts[index]->GetComparison() << " " << sorts[index]->GetPermutation() << std::endl;
		}
		else {
			FileRecorder << sorts[index]->GetName() << " " << sorts[index]->GetComparison() << " " << sorts[index]->GetPermutation() << std::endl;
		}
	}
	std::cout << "Данные успешно сохранены" << std::endl;

	FileRecorder.close();
}

