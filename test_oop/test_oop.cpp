#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Елена\Documents\GitHub\wisdom_oop\source.cpp"
#include "C:\Users\Елена\Documents\GitHub\wisdom_oop\header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testoop
{
	TEST_CLASS(testoop)
	{
	public:
		TEST_METHOD(TestCountSymbols)
		{
			ifstream ifst("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/testCountSymbols.txt");
			wisdom* wd = wisdom::In(ifst);

			int res = wd->CountSymbols();
			int exp = 3;
			Assert::AreEqual(exp, res);
		}
		TEST_METHOD(TestCompare)
		{
			ifstream ifst("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/testCountLetters.txt");
			wisdom* wd1, * wd2;
			wd1 = new aphorism;
			wd2 = new aphorism;

			wd1->In(ifst);
			wd2->In(ifst);
			Node* n1, * n2;
			n1 = new Node(wd1);
			n2 = new Node(wd2);
			bool res = n1->thought->Compare(*n2->thought);
			bool exp = false;
			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(TestInOut)
		{
			ifstream ifst("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/inTest.txt");
			ofstream ofst("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/expTestIn.txt");

			aphorism* a = new aphorism;
			saying* s = new saying;
			riddle* r = new riddle;

			a->InData(ifst);
			s->InData(ifst);
			r->InData(ifst);

			a->Out(ofst);
			s->Out(ofst);
			r->Out(ofst);

			ifstream ifst1("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/expInTest.txt");
			ifstream ifst2("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/expTestIn.txt");
			char c1, c2;
			while (ifst1.get(c1) && ifst2.get(c2))
			{
				Assert::AreEqual(c1, c2);
			}
		}

		TEST_METHOD(TestInputOutput)
		{
			ifstream ifst;
			ifst.open("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/inputTest.txt");
			ofstream ofst;
			ofst.open("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/outputTest.txt");
			container c;

			bool res = true;
			bool exp = true;

			c.In(ifst);
			c.Out(ofst);

			ifstream ifst1("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/expOutputTest.txt");
			ifstream ifst2("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/outputTest.txt");
			char c1, c2;
			while (ifst1.get(c1) && ifst2.get(c2))
			{
				Assert::AreEqual(c1, c2);
			}
		}
		TEST_METHOD(TestClear)
		{
			ifstream ifst;
			ifst.open("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/inputTest.txt");
			ofstream ofst;
			ofst.open("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/clearTest.txt");
			container c;

			bool res = true;
			bool exp = true;

			c.In(ifst);
			c.Clear();
			c.Out(ofst);


			ifstream ifst1("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/clearTest.txt");
			ifstream ifst2("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/expClearTest.txt");
			char c1, c2;
			while (ifst1.get(c1) && ifst2.get(c2))
			{
				Assert::AreEqual(c1, c2);
			}
		}
		TEST_METHOD(TestSort)
		{
			ifstream ifst;
			ifst.open("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/sortTest.txt");
			ofstream ofst;
			ofst.open("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/outSortTest.txt");
			container c;


			c.In(ifst);
			c.Out(ofst);

			ifstream ifst1("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/outSortTest.txt");
			ifstream ifst2("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/expOutSortTest.txt");
			char c1 = ' ', c2 = ' ';
			while (ifst1.get(c1) && ifst2.get(c2))
			{
				Assert::AreEqual(c1, c2);
			}
		}
		TEST_METHOD(TestOutAphorisms)
		{
			ifstream ifst;
			ifst.open("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/aphorismsTest.txt");
			ofstream ofst;
			ofst.open("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/outAphorismsTest.txt");
			container c;

			bool res = true;
			bool exp = true;

			c.In(ifst);
			c.OutAphorisms(ofst);

			ifstream ifst1("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/outAphorismsTest.txt");
			ifstream ifst2("C:/Users/Елена/Documents/GitHub/wisdom_oop/test_oop/expOutAphorismsTest.txt");
			char c1, c2;
			while (ifst1.get(c1) && ifst2.get(c2))
			{
				Assert::AreEqual(c1, c2);
			}
		}
	};
}
