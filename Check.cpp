#include "Check.h"

int GetPositiveInt() //проверка на int
{

    while (true) {
        int value;
        try {
            if (std::cin >> value, std::cin.good()&&value>0) { //cin.good- проверяет состояние потокового ввода
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
              
            }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
        catch (std::invalid_argument& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << e.what() << std::endl; //What()-возвращает последовательность символов, завершающуюся нулем, которая используется для идентификации исключения.
        }
    }
}


int CheckLineI(std::ifstream& file) // проверка введённой из файла строки на int
{
    std::string temp_v = "";
    int temp_d = 0;
    try
    {
        std::getline(file, temp_v);

    }
    catch (const std::exception&)
    {
        std::cout << "Произошла ошибка при чтении информации из фаила: " << std::endl;
        throw 1;

    }
    try
    {
        temp_d = stoi(temp_v);
        if (temp_d <= 0)

        {
            throw  1;
        }
        else {
            return temp_d;
        }
    }
    catch (const std::exception&)
    {
        std::cout << "Неверный тип данных" << std::endl;
        throw 1;
    }
}
std::string CheckLineS(std::ifstream& file) //проверка считанной строки
{
    std::string temp_v = "";
    try
    {
        std::getline(file, temp_v);
        return temp_v;

    }
    catch (const std::exception&)
    {
        std::cout << "Произошла ошибка при чтении информации из фаила:" << std::endl;
        throw 1;

    }
}

int Get3Choise() // выборка из 3 вариантов
{

    while (true) {
        try {

            int value = 0;
            std::cin >> value;
            if (value == 1 || value == 2||value==3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
     
        catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }
}
int GetChoise() // выборка из 2 вариантов
{

    while (true) {
        try {

            int value = 0;
            std::cin >> value;
            if (value == 1 || value == 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
      
        catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }
}
double GetDouble() //проверка чисел на double
{
    while (true) {
        double value=0.;
        try {
            if (std::cin >> value, std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
        }
            else {
                throw std::invalid_argument("Были введены не корректные данные. Повторите ввод.");
            }
        }
        catch (std::invalid_argument& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << e.what() << std::endl;
        }
    }
}
