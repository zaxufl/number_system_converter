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

unordered_map<string, string> Numbers::bin_to_4{
    {"00", "0"},
    {"01", "1"},
    {"10", "2"},
    {"11", "3"},
};

unordered_map<string, string> Numbers::bin_to_8{
    {"000", "0"},
    {"001", "1"},
    {"010", "2"},
    {"011", "3"},
    {"100", "4"},
    {"101", "5"},
    {"110", "6"},
    {"111", "7"},
};

unordered_map<string, string> Numbers::bin_to_16{
    {"0000", "0"},
    {"0001", "1"},
    {"0010", "2"},
    {"0011", "3"},
    {"0100", "4"},
    {"0101", "5"},
    {"0110", "6"},
    {"0111", "7"},
    {"1000", "8"},
    {"1001", "9"},
    {"1010", "A"},
    {"1011", "B"},
    {"1100", "C"},
    {"1101", "D"},
    {"1110", "E"},
    {"1111", "F"},
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
    cout << "Select number: ";

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
        }
    }

    if (from == "binary") {
        user_num = Numbers::checking_binary();
        if (to == "quaternary") {
            ans = Numbers::from_2_to_4816(user_num, 2, bin_to_4);
        } else if (to == "octal") {
            ans = Numbers::from_2_to_4816(user_num, 3, bin_to_8);
        } else if (to == "hexadecimal") {
            ans = Numbers::from_2_to_4816(user_num, 4, bin_to_16);
        } else {
            ans = Numbers::from_2_to_10(user_num);
        }
    }
}

int Numbers::checking_decimal()
{
    int num;

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

int Numbers::checking_binary()
{
    string binary;
    bool checking{true};

    while (checking) {
        cin >> binary;

        for (char &c : binary) {
            if ((c != '0' && c != '1') || binary.length() > 10) {
                cout << "This is not a binary number, try again: ";
                Numbers::cin_clear();
                break;
            }

            if (c == binary[binary.length() - 1]) {
                checking = false;
            }
        }
    }

    int result{};
    result = stoi(binary);

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

string Numbers::from_2_to_4816(int num, int type, unordered_map<string, string> &system)
{
    string result;
    string holder{to_string(num)};
    int checker{static_cast<int>(holder.length()) % type};

    cout << "this is holder length: " << holder.length() << '\n';
    cout << "this is type: " << type << '\n';
    cout << "this is checker: " << checker << '\n';
    int adder{type - checker};

    if (holder.length() % type != 0) {
        holder = string(adder, '0') + holder;
    }

    cout << "this is holder: " << holder << '\n';

    for (int i{}; i < holder.length(); i += type) {
        string sub{holder.substr(i, type)};
        cout << "this is sub: " << sub << '\n';
        result += system[sub];
    }

    cout << "this is result: " << result << '\n';

    return result;
}

string Numbers::from_2_to_10(int num)
{
    int result{};
    string holder{to_string(num)};
    int len{static_cast<int>(holder.length()) - 1};

    for (char &c : holder) {
        if (c == '1') {
            int multi{static_cast<int>(pow(2, len))};
            result += multi;
        }

        --len;
    }

    string ans{};
    ans = to_string(result);

    return ans;
}

void Numbers::show_answer()
{
    cout << "Converting number " << user_num << " from " << from << " to " << to << " is: " << ans
         << '\n';
}
