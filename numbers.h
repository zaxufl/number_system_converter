#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
using namespace std;

class Numbers
{
private:
    static vector<string> number_system;
    string from;
    string to;
    variant<string, double> user_num{};
    static unordered_map<string, string> base_2_to_4;

public:
    Numbers();
    const static void cin_clear();
    static const string selecting_system(const string);
    void from_system();
    void to_system();
    void select_num();
    static double checking_num();
    void checking_hex();
    static string decimal_to_binary(double);
    static string calculating_to_binary(int);
    static string from_2_to_4(string);
    void show_answer();
};

#endif // NUMBERS_H
