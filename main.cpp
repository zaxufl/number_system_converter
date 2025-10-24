#include <QDebug>
#include "numbers.h"
#include <iostream>

using namespace std;

void cin_clear();

int main()
{
    Numbers convert;

    convert.from_system();

    convert.to_system();

    convert.select_num();

    return 0;
}

void cin_clear()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
