#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; //untuk membuat ekor ular
int nTail; //untuk mengatur panjang ekor ular
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw() //untuk membuat border
{
	system("cls"); //system("clear");
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x) //untuk membuat kepala ular
				cout << "O";
			else if (i == fruitY && j == fruitX) //untuk membuat makanan ular
				cout << "F";
			else
				cout << " ";
			
			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}
	
	for (int i = 0; i < width+2 ; i++)
		cout <<"#";
	cout << endl;
	cout << "Score : " << score << endl;
}

void Input() //tombol agar ular bergerak
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width || x < 0 || y > height || y < 0)
		gameOver = true;
	
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}

int main()
{
	
	Setup();
	while(!gameOver)
	{
		Draw();
		
	if (dir == LEFT || dir == RIGHT)
	{
		Sleep(5);
	}
	
	Sleep (100);
	
	if (dir == UP || dir == DOWN)
	{
	Sleep(60);
	}
		
		Input();
		Logic();
		//Sleep(10); sleep(10);
	}
	
	return 0;
}
