#include "pch.h"
#include "CppUnitTest.h"
#include "..\四则运算生成\Four_operations.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Four_operations fo;
			int kuohao = 1;//括号(1表示需要，0表示不需要)
			int add = 1;//加法
			int sub = 1;//减法
			int mul = 1;//乘法
			int div = 1;//除法
			int fl = 1;//小数
			int max = 100;//最大值
			fo.putall(100, 1, 1, 1, 1, 1, 1, 1, 1, 0);//Max, needkuohao, needadd, needsub, needmul, needdiv, needprint, needwritetofile, needfloat, needansw;
			fo.putnum(20);//num
			fo.cal(12.56, 2.36, 8.35, '/', '*', 1);//a，b，c，d，e,，kuohao
			Assert::AreEqual(20, fo.num);

		}
		TEST_METHOD(TestMethod2)
		{
			Four_operations fo;
			int kuohao = 1;//要括号
			int add = 1;
			int sub = 0;//不要减法
			int mul = 1;
			int div = 1;
			int fl = 1;//要小数
			int max = 100;//100以内
			fo.putall(100, 1, 1, 0, 1, 1, 1, 1, 1, 0);//Max, needkuohao, needadd, needsub, needmul, needdiv, needprint, needwritetofile, needfloat, needansw;
			fo.putnum(30);//num
			fo.cal(82.56, 25.36, 2.35, '+', '*', 1);//
			Assert::AreEqual(30, fo.num);

		}
		TEST_METHOD(TestMethod3)
		{
			Four_operations fo;
			int kuohao = 0;//不要括号
			int add = 1;
			int sub = 0;//不要减法
			int mul = 0;//不要乘法
			int div = 1;
			int fl = 1;
			int max = 10;//10以内
			fo.putall(10, 0, 1, 0, 0, 1, 1, 1, 1, 0);//Max, needkuohao, needadd, needsub, needmul, needdiv, needprint, needwritetofile, needfloat, needansw;
			fo.putnum(30);//num
			fo.cal(5.36, 2.58, 0.25, '/', '/', 0);
			Assert::AreEqual(30, fo.num);

		}

		TEST_METHOD(TestMethod4)
		{
			Four_operations fo;
			int kuohao = 1;//要括号
			int add = 1;
			int sub = 0;
			int mul = 0;
			int div = 1;
			int fl = 0;//不要小数
			int max = 10;//10以内
			fo.putall(10, 1, 1, 0, 0, 1, 1, 1, 0, 0);//Max, needkuohao, needadd, needsub, needmul, needdiv, needprint, needwritetofile, needfloat, needansw;
			fo.putnum(30);//num
			fo.cal(6, 2, 3, '+', '/', 0);
			Assert::AreEqual(30, fo.num);

		}

		TEST_METHOD(TestMethod5)
		{
			Four_operations fo;
			int kuohao = 1;//要括号
			int add = 1;
			int sub = 1;
			int mul = 0;//不要乘法
			int div = 0;//不要除法
			int fl = 0;//不要小数
			int max = 100;//100以内
			int answ = 1;//现场答题
			fo.putall(100, 1, 1, 1, 0, 0, 1, 1, 0, 1);//Max, needkuohao, needadd, needsub, needmul, needdiv, needprint, needwritetofile, needfloat, needansw;
			fo.putnum(20);//num
			fo.cal(45, 3, 5, '+', '-', 0);
			Assert::AreEqual(20, fo.num);

		}
	};
}
