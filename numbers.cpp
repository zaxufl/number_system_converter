#include "numbers.h"
#include <QDebug>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

vector<string> Numbers::number_system{"decimal", "binary", "octal", "hexadecimal"};

Numbers::Numbers()
{
    qInfo() << "Welcome to number system converter.";
    qInfo() << "\tDecimal";
    qInfo() << "\tBinary";
    qInfo() << "\tOctal";
    qInfo() << "\tHexadecimal";

    qInfo();
};

void Numbers::cin_clear()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string Numbers::selecting_system(string message)
{
    cout << message;

    string system;

    while (true) {
        cin >> system;

        transform(system.begin(), system.end(), system.begin(), [](unsigned char c) {
            return tolower(c);
        });

        if (find(number_system.begin(), number_system.end(), system) != number_system.end()) {
            return system;
        } else {
            cout << "Wrong number system, try again: ";
            Numbers::cin_clear();
        }
    }
}

void Numbers::from_system()
{
    from = Numbers::selecting_system("From what system number you want convert?: ");
};

void Numbers::to_system()
{
    while (true) {
        to = Numbers::selecting_system("To what number system?: ");
        if (to != from) {
            break;
        } else {
            cout << "Can't be the same system.\n";
        }
    }
};

void Numbers::select_num()
{
    if (from == "hexadecimal") {
        string num;
    } else if (from == "decimal") {
        user_num = Numbers::checking_num();
    }
}

double Numbers::checking_num()
{
    double num;

    while (true) {
        cin >> num;

        if (!cin.good()) {
            cout << "Wrong number, try again: ";
            Numbers::cin_clear();
        } else {
            break;
        }
    }
}
