// WUNSZ.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<string>
#include<ctime>
#include<conio.h>

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
	
	cout << pktX << endl;
	cout << pktY << endl;
	cout << x << endl;
	cout << y << endl;
}

void Draw()
{
	system("cls");
	cout <<"pktX " << pktX << endl;
	cout <<"pktY " << pktY << endl;
	cout << "X " << x << endl;
	cout << "Y " << y << endl;
	for (int i = 0; i < szer + 6; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "WUNSZ RZECZNY TU DUDU TU DUDU v1.0 \n";
	cout << "Sterowanko: \n W - RUCH DO GURY \n S - RUCH DO DOU \n A - RUCH W LEWO \n D - RUCH W PRAWO \n X - WYUONCZENIE GRY";
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
