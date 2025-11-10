#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Numbers
{
private:
    static vector<string> number_system;
    static unordered_map<string, string> bin_to_4;
    static unordered_map<string, string> bin_to_8;
    static unordered_map<string, string> bin_to_16;
    static unordered_map<char, string> quater_to_2;
    static vector<char> binary_nums;
    static vector<char> quaternary_nums;
    string from;
    string to;
    int user_num{};
    string ans;

public:
    Numbers();
    const static void cin_clear();
    static const string selecting_system(const string);
    void from_system();
    void to_system();
    void select_num();
    static int checking_decimal();
    static int checking_systems(vector<char>);
    static string from_decimal(int, int);
    static string from_10_to_24816(int, int);
    static string from_2_to_4816(int, int, unordered_map<string, string> &);
    static string from_2_to_10(int);
    static string from_4_to_2816(unordered_map<char, string>, int);
    void show_answer();
};

#endif // NUMBERS_H
