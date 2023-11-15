#include "pch.h"
#include "CppUnitTest.h"
#include "../LB8.2/LB8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(RemoveNonLettersTest)
        {
            string input = "Hello 123 World!";
            string expectedOutput = "HelloWorld";

            string actualOutput = RemoveNonLetters(input);

            Assert::AreEqual(actualOutput, expectedOutput);
        }
	};
}
