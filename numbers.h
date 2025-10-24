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
    variant<string, int> user_num{};

public:
    Numbers();
    static void cin_clear();
    static string selecting_system(string);
    void from_system();
    void to_system();
    void select_num();
    static int checking_num();
    void checking_hex();
    static void decimal_to_binary(int &);
};

#endif // NUMBERS_H
