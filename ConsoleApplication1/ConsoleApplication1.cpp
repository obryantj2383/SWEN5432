// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "ieee754.h"

using namespace std;


// Main Program
int main()
{

    // Instantiate the union
    myfloat var;

    // Get the real value
    var.f = -2.25;

    // Get the IEEE floating point representation
    cout << "IEEE 754 representation of ";
    cout << fixed << setprecision(6) << var.f << " is : " << endl;
    printIEEE(var);

    // Get the 32-bit floating point number
    unsigned int ieee[32]
        = { 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0 };

    // Convert the least significant
    // mantissa part (23 bits)
    // to corresponding decimal integer
    unsigned int f = convertToInt(ieee, 9, 31);

    // Assign integer representation of mantissa
    var.raw.mantissa = f;

    // Convert the exponent part (8 bits)
    // to a corresponding decimal integer
    f = convertToInt(ieee, 1, 8);

    // Assign integer representation
    // of the exponent
    var.raw.exponent = f;

    // Assign sign bit
    var.raw.sign = ieee[0];

    cout << "The float value of the given"
        " IEEE-754 representation is : \n";
    cout << fixed << setprecision(6) << var.f << endl;
    return 0;
}
