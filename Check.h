#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include <limits>
int GetPositiveInt(); //�������� �� int ��� ����� � ��������
int CheckLineI(std::ifstream& file); // �������� �� int ��� ����� � �������� �� �����
std::string CheckLineS(std::ifstream& file); // �������� ������������� �����
int GetChoise(); // ������� �� 2
int Get3Choise();// ������� �� 3
double GetDouble(); // �������� ����� �� double