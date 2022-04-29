// Copyright (c) 2022 Nicolas Riscalas All rights reserved.
//
// Created by: Nicolas Riscalas
// Created on:April 25 2022
// This program makes a random number game

#include <stdlib.h>
#include <iostream>

using std::cout;
using std::cin;
using std::string;

int main() {
    while (true) {
        // get first input
        string totNumStr, sumEquation, numAsString;
        int totNum, sum, counter, num;
        cout << "How many numbers would you like to add: ";
        cin >> totNumStr;
        // try catch
        try {
            totNum = std::stoi(totNumStr);
            if (totNum < 0) {
                cout << "The total amount cannot be negative\n";
                continue;
            } else {
                sumEquation = "";
                sum = 0;
                counter = 0;
                do {
                    cout << "What number would you like to add: \n";
                    cin >> numAsString;
                    try {
                        num = std::stoi(numAsString);
                        if (num > 0) {
                            ++counter;
                            sum = num + sum;
                            cout << num << " added to total sum\n";
                            if (counter == 1) {
                                sumEquation = numAsString;
                            } else {
                                sumEquation = sumEquation +" + "+ numAsString;
                            }
                        } else {
                            cout << "your number cannot be 0\n";
                            continue;
                        }
                    } catch (std::invalid_argument) {
                        cout << "your number has to be an integer\n";
                        continue;
                    }
                } while (counter < totNum);
                cout << sumEquation << " = " << sum << "\n";
            }
        } catch (std::invalid_argument) {
            cout << "your total number has to be an int\n";
            continue;
        }
    }
}
