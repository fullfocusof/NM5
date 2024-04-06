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

	string table = "Точность eps\t\tЗначение x\t\tЗначение y\t\tИтерации\t\tНевязка1\t\tНевязка2";

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