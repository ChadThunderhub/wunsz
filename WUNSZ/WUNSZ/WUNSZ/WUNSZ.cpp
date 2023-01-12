// WUNSZ.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
/*
ściąga na teleport węża
if (playerPos.X <= 0) playerPos.X += 1;
		if (playerPos.X >= 19) playerPos.X -=1;
		if (playerPos.Y <= 0) playerPos.Y += 1;
		if (playerPos.Y >= 19) playerPos.Y -= 1

*/
/*
if (x <= 0) x += 1;
if (x >= 19) x -= 1;
if (y <= 0) y += 1;
if (y >= 19) y -= 1
*/
#include <iostream>
#include<string>
#include<ctime>
#include<conio.h>
#include<Windows.h>

using namespace std;

bool koniecGry;
const int wys = 20;
const int szer = 20;
int x, y, pktX, pktY, wynik;
enum kierunek{ STOP = 0, LEFT, RIGHT, UP, DOWN };
kierunek dir;

void Setup();
void Draw();
void Logic();
void Input();


int main()
{
		Setup();
		while (!koniecGry)
		{
			Draw();
			Logic();
			Input();
			Sleep(20);
		}
}


void Setup()
{
	srand(time(NULL));
	koniecGry = false;
	dir = STOP;
	x = szer / 2;
	y = wys / 2;
	pktX = rand() % szer-1;
	pktY = rand() % wys-1;
}

void Draw()
{
	system("cls");
	
	
	for (int i = 0; i < szer + 30; i++)
	{
		cout << "#";
	}
	
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j <= szer + 30; j++)
		{
			if (j == 0 || j == szer + 30)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
	cout << endl;
	}
	cout << "# WUNSZ RZECZNY TU DUDU TU DUDU                   #" << endl;
	cout << "#                                                 #" << endl;
	cout << "# Sterowanko:                                     #" << endl;
	cout << "#  W - RUCH DO GORY                               #" << endl;
	cout << "#  S - RUCH DO DOU                                #" << endl;
	cout << "#  A - RUCH W LEWO                                #" << endl;
	cout << "#  D - RUCH W PRAWO                               #" << endl;
	cout << "#  X - WYJSCIE Z GRY                              #" << endl;
	cout << "#                                                 #" << endl;
	for (int i = 0; i < szer + 31; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << endl;
	

	for (int i = 0; i < szer+1; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < wys; i++)
	{
		for (int j = 0; j < szer; j++)
		{
			if (j == 0 || j == szer-1)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "O";
			}
			else if (i == pktX && j == pktY)
			{
				cout << "X";
			}
			else
			{
				cout << " ";
			}
		}
	cout << endl;
	}

	for (int i = 0; i < szer+1; i++)
	{
		cout << "#";
	}
	cout << endl;
	
	cout << "Kordy: \n";
	cout << "pktX " << pktX << endl;
	cout << "pktY " << pktY << endl;
	cout << "X " << x << endl;
	cout << "Y " << y << endl;
	
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			koniecGry = true;
			break;
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}
	if (x <= -1) x += 1;
	if (x >= 19) x -= 1;
	if (y <= -1) y += 1;
	if (y >= 20) y -= 1;
}
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
