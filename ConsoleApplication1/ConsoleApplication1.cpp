// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "ieee754.h"
#include <string>

using namespace std;


// Main Program
int main()
{
    char activity;
    char numberFormat;
    bool activityValid;
    bool numberFormatValid;
    string numberFormatString;
    string numberFromUser;
    unsigned int *ieee;
    string binStr;
    string hexStr;
 

    // Instantiate the union
    myfloat var{};

    // Get the real value
    //var.f = -2.25;

    // Get the IEEE floating point representation
    cout << "This application will allow you to several different operations with floating point numbers.\n";
    cout << "Which activity would you like to do?\n(T)ransform a floating point number from one format to another.\n(C)alculate the value of two numbers and show their IEEE 754 binary, decimal, and hexadecimal formats.\n";
    cout << "Your choice: ";
    cin >> activity;
    activityValid = activity == 't' || activity == 'T' || activity == 'c' || activity == 'C';
    while (!activityValid) {
        cout << activity << " is not available as an option for this step. Please type either t, T, c, or C.\n";
        cout << "Your choice: ";
        cin >> activity;
        activityValid = activity == 't' || activity == 'T' || activity == 'c' || activity == 'C';
    }
    if (activity == 'T' || activity == 't') {
        cout << "\n\nFORMAT TRANSFORMER";
        cout << "Is the number you're providing (h)exadecimal, (d)ecimal, or (b)inary?\n";
        cout << "Your choice: ";
        cin >> numberFormat;
        numberFormatValid = numberFormat == 'h' || numberFormat == 'H' || numberFormat == 'd' || numberFormat == 'D' || numberFormat == 'b' || numberFormat == 'B';
        while (!numberFormatValid) {
            cout << numberFormat << " is not available as an option for this step. Please type either h, H, d, D, b, or B.\n";
            cout << "Your choice: ";
            cin >> activity;
            numberFormatValid = numberFormat == 'h' || numberFormat == 'H' || numberFormat == 'd' || numberFormat == 'D' || numberFormat == 'b' || numberFormat == 'B';
        }
        if (numberFormat == 'h' || numberFormat == 'H') {
            cout << "Please type the number in hexadecimal format: ";
            cin >> numberFromUser;
            hexStr = numberFromUser;
            binStr = convertHexStrToBinStr(numberFromUser);
            ieee = convertStrToIntArr(binStr);
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
        }
        else if (numberFormat == 'd' || numberFormat == 'D') {
            cout << "Please type the number in decimal format: ";
            cin >> numberFromUser;
            var.f = std::stof(numberFromUser);
            binStr = to_string(var.raw.sign) + returnBinary(var.raw.exponent, 8) + returnBinary(var.raw.mantissa, 23);
            cout << "\n";
        }
        else {
            cout << "Please type the number in binary format: ";
            cin >> numberFromUser;
            ieee = convertStrToIntArr(numberFromUser);
            binStr = numberFromUser;
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
        }

        cout << "IEEE 754 representation: ";
        printIEEE(var);
        cout << "Decimal representation: ";
        cout << fixed << setprecision(6) << var.f << endl;
        cout << "Hexadecimal representation: ";
        cout << convertBinStrToHexStr(binStr);

        return 0;
    }
    else {

    }
}
