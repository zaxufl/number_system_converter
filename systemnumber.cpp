#include "systemnumber.h"
#include <QDebug>
#include <iostream>
using namespace std;

const vector<string> SystemNumber::system_digits{"01",
                                                 "0123",
                                                 "01234567",
                                                 "0123456789",
                                                 "0123456789ABCDEF"};

vector<string> SystemNumber::system_numbers{"binary",
                                            "quaternary",
                                            "octal",
                                            "decimal",
                                            "hexadecimal"};

const unordered_map<string, string> SystemNumber::binary_quaternary{
    {"00", "0"},
    {"01", "1"},
    {"10", "2"},
    {"11", "3"},
};

const unordered_map<string, string> SystemNumber::binary_octal{
    {"000", "0"},
    {"001", "1"},
    {"010", "2"},
    {"011", "3"},
    {"100", "4"},
    {"101", "5"},
    {"110", "6"},
    {"111", "7"},
};

const unordered_map<string, string> SystemNumber::binary_hexadecimal{
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

const unordered_map<char, string> SystemNumber::quaternary_binary{
    {'0', "00"},
    {'1', "01"},
    {'2', "10"},
    {'3', "11"},
};

const unordered_map<char, string> SystemNumber::octal_binary{
    {'0', "000"},
    {'1', "001"},
    {'2', "010"},
    {'3', "011"},
    {'4', "100"},
    {'5', "101"},
    {'6', "110"},
    {'7', "111"},
};
const unordered_map<char, string> SystemNumber::hexadecimal_binary{
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"},
};

string SystemNumber::user_num;
string SystemNumber::result;

SystemNumber::SystemNumber()
{
    cout << "Welcome to number system converter." << '\n';
    cout << "You can convert numbers from and to the following list (select by number):" << '\n';

    vector<string> list{SystemNumber::system_numbers};

    for (int i{}; i < list.size(); ++i) {
        list[i][0] = toupper(list[i][0]);
        cout << '\t' << i + 1 << ". " << list[i] << '\n';
    }
    qInfo();
}

void SystemNumber::cin_clear()
{
    cin.clear();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

const void SystemNumber::user_selecting_systems(string message)
{
    cout << message;

    int i{};
    string s{};
    while (true) {
        cin >> s;

        bool ok{!s.empty() && all_of(s.begin(), s.end(), ::isdigit)};

        if (ok) {
            i = stoi(s);
            i -= 1;

            if (i > 4 || i < 0) {
                cout << "Wrong system number, try again: ";
                SystemNumber::cin_clear();
            } else {
                break;
            }
        } else {
            cout << "Wrong system number, try again: ";
            SystemNumber::cin_clear();
        }
    }

    cout << "(" << SystemNumber::system_numbers[i] << ")" << '\n';

    if (from_system == 10) {
        from_system = i;
    } else {
        to_system = i;
    }
}

const void SystemNumber::user_selecting_number()
{
    cout << "Select number to convert:";
    string s;
    bool errors{};

    while (true) {
        cin >> s;

        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return toupper(c); });

        errors = false;

        for (char c : s) {
            if (SystemNumber::system_digits[from_system].find(c) == string::npos) {
                cout << "Wrong number, try again: ";
                SystemNumber::cin_clear();
                errors = true;
                break;
            }
        }

        if (!errors) {
            break;
        }
    }

    user_num = SystemNumber::removing_front_zeros(s);
}

string SystemNumber::binary_decimal_func()
{
    long long num{};
    int len{static_cast<int>(user_num.length())};

    for (int i{}; i < len; ++i) {
        if (user_num[i] == '1') {
            num += pow(2, (len - i - 1));
        }
    }

    string ans{to_string(num)};

    return ans;
}

const void SystemNumber::choosing_calculating_system()
{
    temp_binary = user_num;

    if (from_system == 1) {
        user_num = SystemNumber::x_binary(quaternary_binary);
    } else if (from_system == 2) {
        user_num = SystemNumber::x_binary(octal_binary);
    } else if (from_system == 3) {
        user_num = SystemNumber::decimal_binary();
    } else if (from_system == 4) {
        user_num = SystemNumber::x_binary(hexadecimal_binary);
    }

    if (to_system == 1) {
        result = SystemNumber::calculating(SystemNumber::binary_quaternary, 2);
    } else if (to_system == 2) {
        result = SystemNumber::calculating(SystemNumber::binary_octal, 3);
    } else if (to_system == 3) {
        result = SystemNumber::binary_decimal_func();
    } else if (to_system == 4) {
        result = SystemNumber::calculating(SystemNumber::binary_hexadecimal, 4);
    }

    user_num = temp_binary;
}

const string SystemNumber::removing_front_zeros(string s)
{
    int front_zeros{};

    for (char c : s) {
        if (c == '0') {
            ++front_zeros;
        } else {
            break;
        }
    }

    s = s.substr(front_zeros);

    return s;
}

const string SystemNumber::calculating(unordered_map<string, string> sys, int n)
{
    string ans;
    string temp{SystemNumber::user_num};
    int len{static_cast<int>(SystemNumber::user_num.length())};

    if (len % n != 0) {
        temp = string(n - (len % n), '0') + temp;
    }

    for (int i{}; i < temp.length(); i += n) {
        ans += sys[temp.substr(i, n)];
    }
    return ans;
}

string SystemNumber::decimal_binary()
{
    string ans;
    int user_copy{stoi(SystemNumber::user_num)};

    while (user_copy > 0) {
        ans += to_string(user_copy % 2);
        user_copy /= 2;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

string SystemNumber::x_binary(unordered_map<char, string> sys)
{
    string ans;

    for (char c : SystemNumber::user_num) {
        ans += sys[c];
    }

    ans = SystemNumber::removing_front_zeros(ans);

    return ans;
}

void SystemNumber::print_result()
{
    cout << "Converted number " << user_num << " from " << SystemNumber::system_numbers[from_system]
         << " to " << SystemNumber::system_numbers[to_system] << " is: " << result << '\n';
}
