#include "SystemOfNonlinearEquation.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_BACKSPACE 8

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int main()
{
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_SHOWMAXIMIZED);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	setlocale(LC_ALL, "ru");
	SetConsoleTitle(L"СНЛАУ");
	ConsoleCursorVisible(false, 100);

	SystemOfNonlinearEquation test;

	int active_menu = 0;
	int keyInput;
	bool exitProg = false;

	while (!exitProg)
	{
		int x = (csbi.srWindow.Right - csbi.srWindow.Left + 1) / 2 - 20, y = (csbi.srWindow.Bottom - csbi.srWindow.Top + 1) / 2;
		GoToXY(x, y);

		vector<string> menu =
		{
			"Решение СНЛАУ методом простых итераций",
			"      Вывести таблицу сравнений",
			"               Выход"
		};

		for (int i = 0; i < menu.size(); i++)
		{
			if (i == active_menu)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
			}

			GoToXY(x, y++);
			cout << menu[i] << endl;
		}

		keyInput = _getch();
		switch (keyInput)
		{
			case KEY_ESC:
				exit(0);

			case KEY_UP:
			{
				if (active_menu > 0)
				{
					active_menu--;
				}
			}
			break;

			case KEY_DOWN:
			{
				if (active_menu < menu.size() - 1)
				{
					active_menu++;
				}
			}
			break;

			case KEY_ENTER:
			{
				switch (active_menu)
				{
					case 0:
					{
						system("cls");

						float eps;
						cout << "Введите точность вычислений" << endl;
						cin >> eps;

						system("cls");

						test.simpleIterations(eps);

						test.printQuit();
					}
					break;

					case 1:
					{
						system("cls");
						
						test.printTable();

						test.printQuit();
					}
					break;

					case 2:
					{
						system("cls");
						exitProg = true;
					}
					break;
				}
			}
		}
	}
}