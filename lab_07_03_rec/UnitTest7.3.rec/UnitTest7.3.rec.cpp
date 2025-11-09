#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07_03_rec/lab_07_03_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_RecursiveMatrixOps
{
	TEST_CLASS(RecursiveOpsTests)
	{
	public:

		TEST_METHOD(Test_Calc_MixedRows)
		{
			const int ROWS = 3;
			const int COLS = 3;
			int** arr = new int* [ROWS];
			for (int i = 0; i < ROWS; ++i)
				arr[i] = new int[COLS];

			arr[0][0] = 10; arr[0][1] = -5; arr[0][2] = 20;
			arr[1][0] = 1;  arr[1][1] = 2;  arr[1][2] = 3;
			arr[2][0] = -1; arr[2][1] = 0;  arr[2][2] = 1;

			int expected_sum = 25;
			int actual_sum = Calc(arr, ROWS, COLS, 0);

			Assert::AreEqual(expected_sum, actual_sum, L"Calc повернула неправильну суму.");

			for (int i = 0; i < ROWS; ++i) delete[] arr[i];
			delete[] arr;
		}

		TEST_METHOD(Test_Calc_NoNegatives)
		{
			const int K = 2;
			int** arr = new int* [K];
			for (int i = 0; i < K; ++i) arr[i] = new int[K];

			arr[0][0] = 1; arr[0][1] = 2;
			arr[1][0] = 3; arr[1][1] = 4;

			Assert::AreEqual(0, Calc(arr, K, K, 0), L"Calc має повернути 0, якщо немає від'ємних.");

			for (int i = 0; i < K; ++i) delete[] arr[i];
			delete[] arr;
		}

		TEST_METHOD(Test_Match_FindsCorrectIndices)
		{
			const int N = 3;
			int** arr = new int* [N];
			for (int i = 0; i < N; ++i) arr[i] = new int[N];

			arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 3;
			arr[1][0] = 2; arr[1][1] = 5; arr[1][2] = 8;
			arr[2][0] = 3; arr[2][1] = 8; arr[2][2] = 9;

			int* results = new int[N];
			int resCount = 0;

			Match(arr, N, 0, results, resCount);

			Assert::AreEqual(3, resCount, L"Знайдено неправильну кількість співпадінь.");
			Assert::AreEqual(0, results[0], L"Індекс 0 мав співпасти.");
			Assert::AreEqual(1, results[1], L"Індекс 1 мав співпасти.");
			Assert::AreEqual(2, results[2], L"Індекс 2 мав співпасти.");

			delete[] results;
			for (int i = 0; i < N; ++i) delete[] arr[i];
			delete[] arr;
		}

		TEST_METHOD(Test_Match_NoMatches)
		{
			const int N = 2;
			int** arr = new int* [N];
			for (int i = 0; i < N; ++i) arr[i] = new int[N];

			arr[0][0] = 1; arr[0][1] = 2;
			arr[1][0] = 3; arr[1][1] = 4;

			int* results = new int[N];
			int resCount = 0;

			Match(arr, N, 0, results, resCount);

			Assert::AreEqual(0, resCount, L"Не мало бути знайдено жодного співпадіння.");

			delete[] results;
			for (int i = 0; i < N; ++i) delete[] arr[i];
			delete[] arr;
		}
	};
}