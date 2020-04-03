#include "pch.h"
#include "CppUnitTest.h"
#include "../Sum1/Sum1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Cal c;
			int array[5] = { -1,2,4,3,2 };
			Assert::AreEqual(11,c.MaxSum(5,array));
		}
		TEST_METHOD(TestMethod2)
		{
			Cal c;
			int array[5] = { -1,-2,-3,-4,-5 };
			Assert::AreEqual(0, c.MaxSum(5, array));
		}
		TEST_METHOD(TestMethod3)
		{
			Cal c;
			int array[5] = { -2,1,0,1,-1};
			Assert::AreEqual(2, c.MaxSum(5, array));
		}
		TEST_METHOD(TestMethod4)
		{
			Cal c;
			int array[5] = { -2,1,1,2,3 };
			Assert::AreEqual(7, c.MaxSum(5, array));
		}
	};
}
