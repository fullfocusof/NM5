#include "SystemOfNonlinearEquation.h"

SystemOfNonlinearEquation::SystemOfNonlinearEquation()
{

}

float SystemOfNonlinearEquation::getValueFunc1(float x)
{
	return 0.5f - cos(x - 1);
}

float SystemOfNonlinearEquation::getValueFunc2(float y)
{
	return 3.0f - cos(y);
}

float SystemOfNonlinearEquation::getValueDFunc1(float x)
{
	return sin(x - 1);
}

float SystemOfNonlinearEquation::getValueDFunc2(float y)
{
	return sin(y);
}

void SystemOfNonlinearEquation::simpleIterations(float eps)
{
	float xStart = 2.0f, yStart = 0.0f;

	vector<vector<float>> values(2, vector<float>(2));
	values[0][0] = xStart;
	values[0][1] = yStart;
	int iteration = 0;

	float delta;
	string text = "#\tx0i\t\t\ty0i\t\t\tx1i\t\t\ty1i\t\t\tdelta\t\t\tДостигнута ли точность?";

	stringstream ss;
	string temp;
	ss << fixed << setprecision(15);

	do
	{
		values[1][0] = getValueFunc2(values[0][1]);
		values[1][1] = getValueFunc1(values[0][0]);

		delta = max(abs(values[1][0] - values[0][0]), abs(values[1][1] - values[0][1]));

		ss << iteration << "\t" << values[0][0] << "\t" << values[0][1] << "\t" << values[1][0] << "\t" << values[1][1] << "\t" << delta << "\t" << (delta < eps ? "Да" : "Нет");

		if (delta > eps)
		{
			for (int i = 0; i < 2; i++)
			{
				values[0][i] = values[1][i];
			}
		}
	
		temp = ss.str();
		text += "\n" + temp;
		ss.str("");

		iteration++;

	} while (delta > eps);

	cout << text;

	float res1 = 0.5f - cos(values[1][0] - 1) - values[1][1], res2 = 3.0f - values[1][0] - cos(values[1][1]);
	ss.str("");
	ss << eps << "\t" << values[1][0] << "\t" << values[1][1] << "\t" << iteration << "\t\t\t" << res1 << "\t" << res2;
	temp = ss.str();
	table += "\n" + temp;
}

void SystemOfNonlinearEquation::printTable()
{
	cout << table;
}

void SystemOfNonlinearEquation::printQuit()
{
	cout << endl << endl << "Backspace - возврат в меню";

	int answ = _getch();
	bool press = false;

	while (!press)
	{
		if (answ == 8)
		{
			press = true;
			break;
		}
		else
		{
			answ = _getch();
		}
	}

	system("cls");
}

SystemOfNonlinearEquation::~SystemOfNonlinearEquation()
{

}