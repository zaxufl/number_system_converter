#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
#include <vector>
using namespace std;

class Numbers
{
private:
    vector<string> number_system{"decimal", "binary", "octal", "hexadecimal"};
    string from_number;

public:
    Numbers();
    void from_system();
    static void cin_clear();
};

#endif // NUMBERS_H
