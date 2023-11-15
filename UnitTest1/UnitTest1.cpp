#include "pch.h"
#include "CppUnitTest.h"
#include "../LB8.1_REK/LB8.1_REK.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestChangeFunction)
        {
            // Arrange
            char str[101] = "This is a *** test string.";
            char* dest = new char[151];
            dest[0] = '\0';

            // Act
            char* result = Change(dest, str, dest, 0);

            // Assert
            Assert::AreEqual("This is a !! test string.", result);

            // Clean up
            delete[] dest;
        }


        TEST_METHOD(TestFindStrFunction)
        {
            // Arrange
            char str1[101] = "This is a *** test string.";
            char str2[101] = "This is a test string.";

            // Act & Assert
            Assert::IsTrue(findStr(str1, 0));
            Assert::IsFalse(findStr(str2, 0));
        }

	};
}
