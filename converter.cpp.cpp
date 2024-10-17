/***********************************
 * Date written: 04-10-2024
 *
 * Problem statement: This C++ program asks the user for the number of
 * tons and prints out the equivalent in pounds, ounces, kilograms, and grams.
 * The program also prints out the conversion factors used.
 *
 * Input: The number of tons from the input file (tons.txt)
 *
 * Output: The number of tons converted to pounds, ounces, kilograms, and grams,
 * as well as the conversion factors used.
 *
 * Main algorithm:
 *     - Use the file system for both input and output file streams.
 *     - Input the number of tons between 1 and 9.
 *     - Convert the number of tons into the required amounts.
 *     - Output the converted amounts in the output file.
 *     - Output the conversion factors in the output file.
 *     - Close the input and output files.
 *
 * Major variables:
 *     - tons: the number of tons.
 *     - TONS_TO_POUNDS: conversion factor to pounds.
 *     - TONS_TO_OUNCES: conversion factor to ounces.
 *     - TONS_TO_KILOGRAMS: conversion factor to kilograms.
 *     - TONS_TO_GRAMS: conversion factor to grams.
 *
 * Assumptions:
 *     - A ton means 2000 pounds.
 *
 * Program limitations:
 *     - Hardcoded for these four conversions only.
 *     - Basic formatting of output.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Declaring conversion factors
    const int TONS_TO_POUNDS = 2000;
    const int TONS_TO_OUNCES = 32000;
    const float TONS_TO_KILOGRAMS = 907.185;
    const int TONS_TO_GRAMS = 907185;

    // Declaring measurement variables and data types
    int tons;
    int pounds;
    int ounces;
    float kilograms;
    int grams;

    // Creating file stream variables using ifstream and ofstream data types
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("tons.txt");
    // Check if input file opens successfully
    if (!inputFile)
    {
        cout << "Error: Could not open tons.txt for input." << endl;
        return 1;
    }

    // Receiving tons input from input file
    inputFile >> tons;
    if (tons < 1 || tons > 9)
    {
        cout << "Error: Input should be between 1 and 9" << endl
             << endl;
        return 1;
    }

    // Converting tons to other units using the conversion factors
    pounds = tons * TONS_TO_POUNDS;
    ounces = tons * TONS_TO_OUNCES;
    kilograms = tons * TONS_TO_KILOGRAMS;
    grams = tons * TONS_TO_GRAMS;

    outputFile.open("report.txt");
    // Check if output file opens successfully
    if (!outputFile)
    {
        cout << "Error: Could not open report.txt for output." << endl;
        return 1;
    }

    // Write conversions to the output file
    outputFile << tons << " tons to Pounds = " << pounds << " pounds" << endl
               << endl;
    outputFile << tons << " tons to Ounces = " << ounces << " ounces" << endl
               << endl;
    outputFile << tons << " tons to Kilograms = " << kilograms << " kilograms" << endl
               << endl;
    outputFile << tons << " tons to Grams = " << grams << " grams" << endl
               << endl
               << endl;

    // Write conversion factors to the output file
    outputFile << "Conversion factors used:" << endl
               << endl;
    outputFile << "1 ton to pounds =  " << TONS_TO_POUNDS << " pounds" << endl
               << endl;
    outputFile << "1 ton to ounces =  " << TONS_TO_OUNCES << " ounces" << endl
               << endl;
    outputFile << "1 ton to kilograms =  " << TONS_TO_KILOGRAMS << " kilograms" << endl
               << endl;
    outputFile << "1 ton to grams =  " << TONS_TO_GRAMS << " grams" << endl
               << endl;

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}