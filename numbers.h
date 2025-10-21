#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
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

public:
    Numbers();
    static void cin_clear();
    static string selecting_system(string);
    void from_system();
    void to_system();
    void select_num();
    static double checking_num();
    void checking_hex();
    void decimal_to_binary();
};

#endif // NUMBERS_H
