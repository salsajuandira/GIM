#include <iostream>
using namespace std;

const int width = 20;
const int height = 20;

int main()
{
	system("cls"); //system("clear");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			
				cout << " ";
			
			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}
	
	for (int i = 0; i < width + 2 ; i++)
		cout <<"#";
	cout << endl;
}
