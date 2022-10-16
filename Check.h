#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include <limits>
int GetPositiveInt(); //проверка на int для строк и столбцов
int CheckLineI(std::ifstream& file); // проверка на int для строк и столбцов из файла
std::string CheckLineS(std::ifstream& file); // проверка считывающихся строк
int GetChoise(); // выборка из 2
int Get3Choise();// выборка из 3
double GetDouble(); // проверка чисел на double