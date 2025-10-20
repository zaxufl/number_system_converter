#include <QDebug>
#include "numbers.h"
#include <iostream>

using namespace std;

void cin_clear();

int main()
{
    qInfo() << "Welcome to number system converter.";
    qInfo() << "\tDecimal";
    qInfo() << "\tBinary";
    qInfo() << "\tOcatl";
    qInfo() << "\tHexadecimal";

    qInfo();

    Numbers convert;

    convert.from_system();

    return 0;
}

void cin_clear()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
