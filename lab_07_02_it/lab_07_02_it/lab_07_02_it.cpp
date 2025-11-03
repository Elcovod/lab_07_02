#include <iostream>
#include <iomanip>
#include <time.h>
#include <climits>
#include <Windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int MaxIMin(int** a, const int rowCount, const int colCount);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));
	int Low = -25;
	int High = 35;
	int rowCount = 7;
	int colCount = 5;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	int result = MaxIMin(a, rowCount, colCount);
	cout << "Maximin матриці = " << result << endl;
	
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int MaxIMin(int** a, const int rowCount, const int colCount)
{		
	int maxofmins = INT_MIN;

	for (int i = 0; i < rowCount; i++)
	{
		int min_el = a[i][0];
		for (int j = 1; j < colCount; j++)
		{
			if (a[i][j] < min_el)
			{
				min_el = a[i][j];
			}
		}
		if (min_el > maxofmins)
		{
			maxofmins = min_el;
		}
	}   
	return maxofmins;
} 