#include "pch.h"
#include "CppUnitTest.h"
#include "../start/start.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[3] = { 3, 5, 5 };
			char ch[2] = { '+' , '-' };
			int c = 3;
			Level1 Test(arr, ch, c);
			char zn = Test.getAct(2);
			Assert::AreEqual(arr[2], Test.getArg(2));
			Assert::AreEqual('=',zn);
		}
		
	};
}
