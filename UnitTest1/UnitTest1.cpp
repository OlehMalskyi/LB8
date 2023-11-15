#include "pch.h"
#include "CppUnitTest.h"
#include "../LB8.1_CHAR/LB8.1_CHAR.cpp"
#define _CRT_SECURE_NO_WARNINGS

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[] = "abc***def";
			char* result = Change(str);
			Assert::AreEqual("abc!!def", result);
			delete[] result;
		}
	};
}
