#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Project\lab_07_02_it\lab_07_02_it\lab_07_02_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Maximin
{
	TEST_CLASS(MaximinFunctionTest)
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

			Assert::AreEqual(expected_maximin, actual_maximin, L"Функція MaxIMin обчислила невірне значення.");

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}