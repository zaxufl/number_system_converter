#include "numbers.h"
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

Numbers::Numbers() {};

void Numbers::cin_clear()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Numbers::from_system()
{
    cout << "From what system number you want convert?: ";

    string from;

    while (true) {
        cin >> from;

        transform(from.begin(), from.end(), from.begin(), [](unsigned char c) {
            return tolower(c);
        });

        if (find(number_system.begin(), number_system.end(), from) != number_system.end()) {
            from_number = from;
            break;
        } else {
            cout << "Wrong number system, try again: ";
            Numbers::cin_clear();
        }
    }
}
