// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "ieee754.h"
#include <string>
#include "ConsoleApplication1.h"

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
    unsigned int* ieee;
    string binStr;
    string hexStr;
    string signFromUser;
    string exponentFromUser;
    string mantissaFromUser;
 

    // Instantiate the union
    myfloat var{};

    // Get the real value
    //var.f = -2.25;

    // Get the IEEE floating point representation
    cout << "This application will allow you to several different operations with floating point numbers.\n";
    cout << "Which activity would you like to do?\n(T)ransform a floating point number from one format to another.\n(C)alculate the value of two numbers and show their IEEE 754 binary, decimal, and hexadecimal formats.\n";
    cout << "Your choice: ";
    cin >> activity;
    activity = tolower(activity);
    activityValid = activity == 't' || activity == 'c';
    while (!activityValid) {
        cout << activity << " is not available as an option for this step. Please type either t, T, c, or C.\n";
        cout << "Your choice: ";
        cin >> activity;
        activityValid = activity == 't' || activity == 'c';
    }
    if (activity == 'c') {
        char oper;

        float a, b;

        // It allow user to enter the operands 

        cout << "Enter two operands: ";

        cin >> a >> b;

        // It allows user to enter operator i.e. +, -, *, / 

        cout << "Enter operator: ";

        cin >> oper;

        // Switch statement begins 

        switch (oper)

        {

            // If operator is '+'  

        case '+':

            cout << a + b;

            break;

            // If operator is '-'  

        case '-':

            cout << a - b;

            break;

            // If operator is '*' 

        case '*':

            cout << a * b;

            break;

            // If operator is '/' 

        case '/':

            cout << a / b;

            break;

            // If any other operator display error message 

        default:

            cout << "Error! Incorrect operator";

            break;

        }
        if (oper == '+') {
            a += b;
            var.f = a;
            binStr = to_string(var.raw.sign) + returnBinaryStr(var.raw.exponent, 8) + returnBinaryStr(var.raw.mantissa, 23);
        }
        if (oper == '-') {
            a -= b;
            var.f = a;
            binStr = to_string(var.raw.sign) + returnBinaryStr(var.raw.exponent, 8) + returnBinaryStr(var.raw.mantissa, 23);
        }
        if (oper == '/') {
            a /= b;
            var.f = a;
            binStr = to_string(var.raw.sign) + returnBinaryStr(var.raw.exponent, 8) + returnBinaryStr(var.raw.mantissa, 23);
        }
        if (oper == '*') {
            a *= b;
            var.f = a;
            binStr = to_string(var.raw.sign) + returnBinaryStr(var.raw.exponent, 8) + returnBinaryStr(var.raw.mantissa, 23);
        }


        cout << "\nIEEE 754 representation: ";
        printIEEEBinary(var);
        cout << "Decimal representation: ";
        cout << fixed << setprecision(6) << var.f << endl;
        cout << "Hexadecimal representation: ";
        cout << convertBinStrToHexStr(binStr, "0x");


        return 0;

    }
    if (activity == 't') {
        cout << "\nFORMAT TRANSFORMER";
        cout << "\nIs the number you're providing (h)exadecimal, (d)ecimal, (b)inary, or (s)ign/exponent/mantissa?\n";
        cout << "Your choice: ";
        cin >> numberFormat;
        numberFormatValid = numberFormat == 'h'|| numberFormat == 'd' || numberFormat == 'b' || numberFormat == 's';
        while (!numberFormatValid) {
            cout << numberFormat << " is not available as an option for this step. Please type either h, H, d, D, b, B, s, or S.\n";
            cout << "Your choice: ";
            cin >> activity;
            numberFormatValid = numberFormat == 'h' || numberFormat == 'd' || numberFormat == 'b';
        }
        if (numberFormat == 'h') {
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
        else if (numberFormat == 'd') {
            cout << "Please type the number in decimal format: ";
            cin >> numberFromUser;
            var.f = std::stof(numberFromUser);
            binStr = to_string(var.raw.sign) + returnBinaryStr(var.raw.exponent, 8) + returnBinaryStr(var.raw.mantissa, 23);
            cout << "\n";
        }
        else if (numberFormat == 'b') {
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
        else {
            cout << "\nPlease type the sign (0 or 1): ";
            cin >> signFromUser;
            cout << "\nNow provide the exponent in hexadecimal format: ";
            cin >> exponentFromUser;
            cout << "\nNow provide the mantissa in hexadecimal format: ";
            cin >> mantissaFromUser;
            binStr = signFromUser + convertHexStrToBinStr(exponentFromUser) + convertHexStrToBinStr(mantissaFromUser).substr(1, 23);
            ieee = convertStrToIntArr(binStr);
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

        cout << "IEEE 754 binary representation: ";
        printIEEEBinary(var);
        cout << "IEEE 754 hexadecimal representation: ";
        printIEEEHex(var);
        cout << "Decimal representation: ";
        cout << fixed << setprecision(6) << var.f << endl;
        cout << "Hexadecimal representation: ";
        cout << convertBinStrToHexStr(binStr, "0x");

        return 0;
    }
    else {

    }
}

