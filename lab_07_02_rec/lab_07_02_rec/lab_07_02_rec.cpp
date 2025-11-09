#include <iostream>
#include <iomanip>
#include <time.h>	
#include <Windows.h>

using namespace std;

void CreateRecursive(int** arr, const int rowCount, const int colCount, const int LOW, const int HIGH, const int i, const int j);
void PrintRecursive(int** arr, const int rowCount, const int colCount, int i, int j);	
int FindMinInRow(int* arr, const int colCount, int j, int currentMin);
int MaxIMinRecursive(int** arr, const int rowCount, const int colCount, int i, int currentMaximin);

void Create(int** arr, const int rowCount, const int colCount, const int LOW, const int HIGH)
{
	CreateRecursive(arr, rowCount, colCount, LOW, HIGH, 0, 0);
}

void Print(int** arr, const int rowCount, const int colCount)
{
	PrintRecursive(arr, rowCount, colCount, 0, 0);
}

int MaxIMin(int** arr, const int rowCount, const int colCount)
{
	int firstMin = FindMinInRow(arr[0], colCount, 1, arr[0][0]);

	return MaxIMinRecursive(arr, rowCount, colCount, 1, firstMin);

}

void CreateRecursive(int** arr, const int rowCount, const int colCount, const int LOW, const int HIGH, int i, int j)
{
	if (i == rowCount)
		return;

	arr[i][j] = LOW + rand() % (HIGH - LOW + 1);

	if (j + 1 < colCount)
	{
		CreateRecursive(arr, rowCount, colCount, LOW, HIGH, i, j + 1);

	}
	else 
	{
		CreateRecursive(arr, rowCount, colCount, LOW, HIGH, i + 1, 0);
	}
}

void PrintRecursive(int** arr, const int rowCount, const int colCount, int i, int j)
{
	if (i == rowCount)
		return;
	if (j + 1 < colCount)
	{
		cout << setw(4) << arr[i][j];
		PrintRecursive(arr, rowCount, colCount, i, j + 1);
	}
	else
	{
		cout << setw(4) << arr[i][j] << endl;
		PrintRecursive(arr, rowCount, colCount, i + 1, 0);
	}
}

int FindMinInRow(int* row, const int colCount, int j, int currentMin)
{
	if (j == colCount)
		return currentMin;
	if (row[j] < currentMin) 
	{
		currentMin = row[j];
	}
	return FindMinInRow(row, colCount, j + 1, currentMin);
}

int MaxIMinRecursive(int** arr, const int rowCount, const int colCount, int i, int currentMaximin)
{
	if (i == rowCount)
		return currentMaximin;

	int currentMin = FindMinInRow(arr[i], colCount, 1, arr[i][0]);

	if (currentMin > currentMaximin)
	{
		currentMaximin = currentMin;
	}
	return MaxIMinRecursive(arr, rowCount, colCount, i + 1, currentMaximin);
}

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
	cout << endl;

	int result = MaxIMin(a, rowCount, colCount);
	cout << "Maximin матриці = " << result << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}