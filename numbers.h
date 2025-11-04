#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
#include <vector>
using namespace std;

class Numbers
{
private:
    static vector<string> number_system;
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
    void checking_hex();
    static string from_decimal(int, int);
    static string from_10_to_24816(int, int);
    void show_answer();
};

#endif // NUMBERS_H
