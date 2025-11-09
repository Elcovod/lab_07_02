#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Project\lab_07_02_rec\lab_07_02_rec\lab_07_02_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_RecursiveMaximin
{
	TEST_CLASS(RecursiveMaximinTest)
	{
	public:

		TEST_METHOD(Test_MaxIMin_FindsCorrectValue)
		{
			const int rowCount = 3;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 10; a[0][1] = 5;  a[0][2] = 20;
			a[1][0] = 30; a[1][1] = 2;  a[1][2] = 15;
			a[2][0] = 8;  a[2][1] = 12; a[2][2] = 7;

			int expected_maximin = 7;

			int actual_maximin = MaxIMin(a, rowCount, colCount);

			Assert::AreEqual(expected_maximin, actual_maximin, L"MaxIMin returned incorrect value.");

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(Test_FindMinInRow_FindsCorrectMin)
		{
			const int colCount = 5;
			int row[colCount] = { 10, 2, 8, 1, 5 };

			int expected_min = 1;
			int actual_min = FindMinInRow(row, colCount, 1, row[0]);

			Assert::AreEqual(expected_min, actual_min, L"FindMinInRow returned incorrect minimum.");
		}
	};
}