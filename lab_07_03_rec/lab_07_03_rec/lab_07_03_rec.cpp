#include <iostream>
#include <iomanip>

using namespace std;

void Input(int** arr, const int rowcount, const int colcount, int i, int j);
void Print(int** arr, const int rowcount, const int colcount, int i, int j);

bool HasNegative(int** arr, const int colcount, int r, int c);
int SumRow(int** arr, const int colcount, int r, int c);
int Calc(int** arr, const int rowcount, const int colcount, int i);

bool CheckRowColMatch(int** arr, const int n, int k, int i);
void Match(int** arr, const int n, int k, int* results, int& resCount);

int main()
{
    int k;
    cout << "Enter matrix size: ";
    cin >> k;

    int** arr = new int* [k];
    for (int i = 0; i < k; i++)
        arr[i] = new int[k];

    Input(arr, k, k, 0, 0);
    Print(arr, k, k, 0, 0);

    int totalsum = Calc(arr, k, k, 0);
    cout << "Total sum of rows with negative elements: " << totalsum << endl;

    int* matchResults = new int[k];
    int matchCount = 0;

    Match(arr, k, 0, matchResults, matchCount);

    cout << "Indices k where k-th row matches k-th column: ";
    if (matchCount == 0) {
        cout << "None" << endl;
    }
    else {
        for (int i = 0; i < matchCount; i++) {
            cout << matchResults[i] << " ";
        }
        cout << endl;
    }

    delete[] matchResults;
    for (int i = 0; i < k; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

void Input(int** arr, const int rowcount, const int colcount, int i, int j)
{
    if (i >= rowcount) return;

    cout << "arr[" << i << "][" << j << "] = ";
    cin >> arr[i][j];

    if (j + 1 < colcount) {
        Input(arr, rowcount, colcount, i, j + 1);
    }
    else {
        Input(arr, rowcount, colcount, i + 1, 0);
    }
}

void Print(int** arr, const int rowcount, const int colcount, int i, int j)
{
    if (i >= rowcount) return;

    if (j == 0 && i == 0) cout << endl;

    cout << setw(4) << arr[i][j];

    if (j + 1 < colcount) {
        Print(arr, rowcount, colcount, i, j + 1);
    }
    else {
        cout << endl;
        Print(arr, rowcount, colcount, i + 1, 0);
    }
}

bool HasNegative(int** arr, const int colcount, int r, int c) {
    if (c >= colcount) return false;
    if (arr[r][c] < 0) return true;
    return HasNegative(arr, colcount, r, c + 1);
}

int SumRow(int** arr, const int colcount, int r, int c) {
    if (c >= colcount) return 0;
    return arr[r][c] + SumRow(arr, colcount, r, c + 1);
}

int Calc(int** arr, const int rowcount, const int colcount, int i)
{
    if (i >= rowcount) return 0;

    int current_row_sum = 0;
    if (HasNegative(arr, colcount, i, 0)) {
        current_row_sum = SumRow(arr, colcount, i, 0);
    }

    return current_row_sum + Calc(arr, rowcount, colcount, i + 1);
}

bool CheckRowColMatch(int** arr, const int n, int k, int i) {
    if (i >= n) return true;
    if (arr[k][i] != arr[i][k]) return false;
    return CheckRowColMatch(arr, n, k, i + 1);
}

void Match(int** arr, const int n, int k, int* results, int& resCount)
{
    if (k >= n) return;

    if (CheckRowColMatch(arr, n, k, 0)) {
        results[resCount] = k;
        resCount++;
    }

    Match(arr, n, k + 1, results, resCount);
}