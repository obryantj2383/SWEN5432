#pragma once
#include <iostream>
#include <iomanip>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

typedef union {

    float f;
    struct
    {

        // Order is important.
        // Here the members of the union data structure
        // use the same memory (32 bits).
        // The ordering is taken
        // from the LSB to the MSB.
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;

    } raw;
} myfloat;

// This function prints the binary representation of a
// number n up to i bits.
void printBinary(int n, int i)
{

    // Prints the binary representation
    // of a number n up to i-bits.

    int k;
    for (k = i - 1; k >= 0; k--) {

        if ((n >> k) & 1)
            cout << "1";
        else
            cout << "0";
    }
}

string returnBinary(int n, int i)
{

	// Returns the binary representation
	// of a number n up to i-bits.

	int k;
	string bin = "";
	for (k = i - 1; k >= 0; k--) {

		if ((n >> k) & 1)
			bin = bin + "1";
		else
			bin = bin + "0";
	}
	return bin;
}

// This function converts a real value
// to its IEEE floating point representation.
void printIEEE(myfloat var)
{

    // Prints the IEEE 754 representation
    // of a float value (32 bits)

    cout << var.raw.sign << " | ";
    printBinary(var.raw.exponent, 8);
    cout << " | ";
    printBinary(var.raw.mantissa, 23);
    cout << "\n";
}

// This function converts a binary array
// to its corresponding integer representation.
unsigned int convertToInt(unsigned int* arr, int low, int high)
{
    unsigned int f = 0, i;
    for (i = high; i >= low; i--) {
        f = f + arr[i] * pow(2, high - i);
    }
    return f;
}

unsigned int* convertStrToIntArr(string str)
{
    static unsigned int arr[32];
    int i = 0;
    for (i = 0; i < 32; i++) {
        arr[i] = str[i] - '0';
    }
    return arr;
}

string convertBinStrToHexStr(string bin)
{
	string rest("0x"), tmp, chr = "0000";
	int len = bin.length() / 4;
	chr = chr.substr(0, len);
	bin = chr + bin;
	for (int i = 0; i < bin.length(); i += 4)
	{
		tmp = bin.substr(i, 4);
		if (!tmp.compare("0000"))
		{
			rest = rest + "0";
		}
		else if (!tmp.compare("0001"))
		{
			rest = rest + "1";
		}
		else if (!tmp.compare("0010"))
		{
			rest = rest + "2";
		}
		else if (!tmp.compare("0011"))
		{
			rest = rest + "3";
		}
		else if (!tmp.compare("0100"))
		{
			rest = rest + "4";
		}
		else if (!tmp.compare("0101"))
		{
			rest = rest + "5";
		}
		else if (!tmp.compare("0110"))
		{
			rest = rest + "6";
		}
		else if (!tmp.compare("0111"))
		{
			rest = rest + "7";
		}
		else if (!tmp.compare("1000"))
		{
			rest = rest + "8";
		}
		else if (!tmp.compare("1001"))
		{
			rest = rest + "9";
		}
		else if (!tmp.compare("1010"))
		{
			rest = rest + "A";
		}
		else if (!tmp.compare("1011"))
		{
			rest = rest + "B";
		}
		else if (!tmp.compare("1100"))
		{
			rest = rest + "C";
		}
		else if (!tmp.compare("1101"))
		{
			rest = rest + "D";
		}
		else if (!tmp.compare("1110"))
		{
			rest = rest + "E";
		}
		else if (!tmp.compare("1111"))
		{
			rest = rest + "F";
		}
		else
		{
			continue;
		}
	}
	return rest;
}

string convertHexStrToBinStr(string hex)
{
	string rest, tmp, chr = "0000";
	//int len = hex.length() * 4;
	//chr = chr.substr(0, len);
	//hex = chr + bin;
	for (int i = 0; i < hex.length(); i++)
	{
		tmp = hex.substr(i, 1);
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
		if (!tmp.compare("0"))
		{
			rest = rest + "0000";
		}
		else if (!tmp.compare("1"))
		{
			rest = rest + "0001";
		}
		else if (!tmp.compare("2"))
		{
			rest = rest + "0010";
		}
		else if (!tmp.compare("3"))
		{
			rest = rest + "0011";
		}
		else if (!tmp.compare("4"))
		{
			rest = rest + "0100";
		}
		else if (!tmp.compare("5"))
		{
			rest = rest + "0101";
		}
		else if (!tmp.compare("6"))
		{
			rest = rest + "0110";
		}
		else if (!tmp.compare("7"))
		{
			rest = rest + "0111";
		}
		else if (!tmp.compare("8"))
		{
			rest = rest + "1000";
		}
		else if (!tmp.compare("9"))
		{
			rest = rest + "1001";
		}
		else if (!tmp.compare("A"))
		{
			rest = rest + "1010";
		}
		else if (!tmp.compare("B"))
		{
			rest = rest + "1011";
		}
		else if (!tmp.compare("C"))
		{
			rest = rest + "1100";
		}
		else if (!tmp.compare("D"))
		{
			rest = rest + "1101";
		}
		else if (!tmp.compare("E"))
		{
			rest = rest + "1110";
		}
		else if (!tmp.compare("F"))
		{
			rest = rest + "1111";
		}
		else
		{
			continue;
		}
	}
	return rest;
}