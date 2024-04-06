#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

#include <Windows.h>
#include <conio.h>

#include <cmath>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class SystemOfNonlinearEquation
{
	// f1 => cos(x - 1) + y = 0.5
	// f2 => x + cos y = 3

	string table = "�������� eps\t\t�������� x\t\t�������� y\t\t��������\t\t�������1\t\t�������2";

public: 

	SystemOfNonlinearEquation();

	float getValueFunc1(float x);
	float getValueFunc2(float y);
	float getValueDFunc1(float x);
	float getValueDFunc2(float y);

	void simpleIterations(float eps);

	void printTable();
	void printQuit();

	~SystemOfNonlinearEquation();
};