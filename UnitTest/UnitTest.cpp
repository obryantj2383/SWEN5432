#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/ieee754.h"
#include "../ConsoleApplication1/ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(ReturnBinary_Method)
		{
			std::string expectedOutput = "0";
			//Assert::AreEqual(expectedOutput, returnBinary(-1, 7)); //Issue with this scenario
			expectedOutput = "0";
			Assert::AreEqual(expectedOutput, returnBinaryStr(-2, 1));
			expectedOutput = "0100000000000000000000100100101001";
			Assert::AreEqual(expectedOutput, returnBinaryStr(2345, 34));
			expectedOutput = "000000000000000000010111";
			Assert::AreEqual(expectedOutput, returnBinaryStr(23, 24));
		}

		TEST_METHOD(ConvertHexStrToBinStr_Method)
		{
			std::string expectedOutput = "00010010";
			Assert::AreEqual(expectedOutput, convertHexStrToBinStr("12"));
			expectedOutput = "0000";
			Assert::AreEqual(expectedOutput, convertHexStrToBinStr("0"));
			expectedOutput = "0001";
			Assert::AreEqual(expectedOutput, convertHexStrToBinStr("-1"));
			expectedOutput = "0110011101010101";
			Assert::AreEqual(expectedOutput, convertHexStrToBinStr("6755"));
			//expectedOutput = "Invalid Input Error"; 
			//Assert::AreEqual(expectedOutput, convertHexStrToBinStr("X'ABCD'")); //Invalid input Error is not handled in the code.
			//expectedOutput = "Invalid Input Error";
			//Assert::AreEqual(expectedOutput, convertHexStrToBinStr("&*()(("));// Invalid Input Error is not handled in the code
		}

		TEST_METHOD(ConvertStrToIntArr_Method)
		{
			unsigned int expectedArr[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 };
			std::string input = "00000000000000000000000000010010";
			unsigned int* actualArr = convertStrToIntArr(input);
			for (int i = 0; i < 32; i++)
			{
				Assert::AreEqual(expectedArr[i], actualArr[i]); //#Issue2: Error is not handled.
			}
			
		}

		TEST_METHOD(ConvertToInt_Method)
		{
			//unsigned int input[2] = { 1, 2 };
			//unsigned int  expected = "Invalid Input";
			//Assert::AreEqual(expected, convertToInt(input, 0, 1)); //#Issue3: Error is not handled.
		}

		TEST_METHOD(ConvertBinStrToHexStr_Method)
		{
			std::string expectedOutput = "0x4A";
			Assert::AreEqual(expectedOutput, convertBinStrToHexStr("01001010", "0x"));
			expectedOutput = "0x";
			Assert::AreEqual(expectedOutput, convertBinStrToHexStr("0", "0x"));
			expectedOutput = "0x";
			Assert::AreEqual(expectedOutput, convertBinStrToHexStr("-1", "0x"));
			expectedOutput = "0x";
			Assert::AreEqual(expectedOutput, convertBinStrToHexStr("test", "0x")); //#Issue3: Should we throw an error message for invalid inputs
		}
	};
}
