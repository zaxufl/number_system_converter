#ifndef SYSTEMNUMBER_H
#define SYSTEMNUMBER_H
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::unordered_map;
using std::vector;

class SystemNumber
{
private:
    static string user_num;
    static string result;
    string temp_binary;
    int from_system{10};
    int to_system{50};
    static vector<string> system_numbers;
    const static vector<string> system_digits;
    const static unordered_map<string, string> binary_quaternary;
    const static unordered_map<string, string> binary_octal;
    const static unordered_map<string, string> binary_hexadecimal;
    const static unordered_map<char, string> quaternary_binary;
    const static unordered_map<char, string> octal_binary;
    const static unordered_map<char, string> hexadecimal_binary;

public:
    SystemNumber();
    inline void cin_clear();
    const void user_selecting_systems(string);
    const void user_selecting_number();
    string binary_decimal_func();
    static string decimal_binary();
    static string x_binary(unordered_map<char, string>);
    const void choosing_calculating_system();
    static const string calculating(unordered_map<string, string>, int);
    static const string removing_front_zeros(string);
    void print_result();
};

#endif // SYSTEMNUMBER_H
