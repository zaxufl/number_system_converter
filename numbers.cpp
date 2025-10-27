#include "numbers.h"
#include <QDebug>
#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_map>
using namespace std;

vector<string> Numbers::number_system{
    "decimal",
    "binary",
    "quaternary",
    "octal",
    "hexadecimal",
};

unordered_map<string, string> Numbers::base_2_to_4{{"00", "0"},
                                                   {"01", "1"},
                                                   {"10", "2"},
                                                   {"11", "3"}};

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
    user_num = Numbers::checking_num();
    user_num = Numbers::decimal_to_binary(get<double>(user_num));
    if (from == "decimal" && to == "quaternary") {
        user_num = Numbers::from_2_to_4(get<string>(user_num));
    } else if (from == "222") {
    }
}

double Numbers::checking_num()
{
    double num;

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

string Numbers::decimal_to_binary(double user_num)
{
    string result;

    if (fmod(user_num, 1) == 0) {
        int num{};
        num = user_num;
        result = Numbers::calculating_to_binary(num);
    } else {
        int left{};
        left = trunc(user_num);

        string right{};
        right = to_string(user_num - trunc(user_num)).substr(2);
        size_t multipler{};

        for (char c : right) {
            if (c == '0') {
                ++multipler;
            } else {
                break;
            }
        }

        string zeros{"0", multipler};

        int num_right{};
        num_right = stoi(right);
        result = Numbers::calculating_to_binary(left);
        result += "." + zeros + Numbers::calculating_to_binary(num_right);
    }

    result = result.substr(0, 18);

    return result;
}

string Numbers::calculating_to_binary(int num)
{
    string s_num{};

    while (num > 0) {
        s_num += to_string(num % 2);
        num /= 2;

        if (s_num.length() > 18) {
            break;
        }
    }

    reverse(s_num.begin(), s_num.end());

    return s_num;
}

string Numbers::from_2_to_4(string num)
{
    string starting_num;

    if (num.length() % 2 != 0) {
        starting_num += "0" + num;
    } else {
        starting_num = num;
    }

    string result;

    for (int i{}; i < starting_num.length() / 2; ++i) {
        result += base_2_to_4[starting_num.substr(i * 2, 2)];
    }

    return result;
}

void Numbers::show_answer()
{
    cout << "Converting number from " << from << " to " << to << " is: " << get<string>(user_num)
         << '\n';
}
