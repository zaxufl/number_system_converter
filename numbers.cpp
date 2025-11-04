#include "numbers.h"
#include <QDebug>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

vector<string> Numbers::number_system{
    "decimal",
    "binary",
    "quaternary",
    "octal",
    "hexadecimal",
};

Numbers::Numbers()
{
    qInfo() << "Welcome to number system converter.";

    for (string s : Numbers::number_system) {
        s[0] = toupper(s[0]);
        cout << "\t" << s << '\n';
    }
    qInfo();
};

const void Numbers::cin_clear()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

const string Numbers::selecting_system(const string message)
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
    if (from == "decimal") {
        user_num = Numbers::checking_decimal();
        if (to == "quaternary") {
            ans = Numbers::from_decimal(user_num, 4);
        } else if (to == "octal") {
            ans = Numbers::from_decimal(user_num, 8);
        } else if (to == "hexadecimal") {
            ans = Numbers::from_decimal(user_num, 16);
        } else if (to == "binary") {
            ans = Numbers::from_decimal(user_num, 2);
        } else {
        }
    }
}

int Numbers::checking_decimal()
{
    int num;

    cout << "Select number: ";

    while (true) {
        cin >> num;

        if (!cin.good()) {
            cout << "Wrong number, try again: ";
            Numbers::cin_clear();
        } else {
            return num;
        }
    }
}

string Numbers::from_decimal(int user_num, int n)
{
    string result;

    int num{};
    num = user_num;
    result = Numbers::from_10_to_24816(num, n);

    return result;
}

string Numbers::from_10_to_24816(int num, int n)
{
    string s_num{};

    while (num > 0) {
        int divider{num % n};

        if (n == 16 && divider >= 10) {
            if (divider == 10) {
                s_num += "A";
            } else if (divider == 11) {
                s_num += "B";
            } else if (divider == 12) {
                s_num += "C";
            } else if (divider == 13) {
                s_num += "D";
            } else if (divider == 14) {
                s_num += "E";
            } else {
                s_num += "F";
            }
        } else {
            s_num += to_string(divider);
        }

        num /= n;
    }

    reverse(s_num.begin(), s_num.end());

    return s_num;
}

void Numbers::show_answer()
{
    cout << "Converting number from " << from << " to " << to << " is: " << ans << '\n';
}
