#pragma once
#include <iostream>
#include <iomanip>

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