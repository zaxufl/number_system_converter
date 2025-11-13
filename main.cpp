#include "systemnumber.h"
#include <iostream>
using std::cout;

int main()
{
    string first_message{"Which number system do you want to convert the number from?: "};
    string second_message{"To what system number?: "};

    SystemNumber converter;

    converter.user_selecting_systems(first_message);

    converter.user_selecting_systems(second_message);

    converter.user_selecting_number();

    converter.choosing_calculating_system();

    converter.print_result();

    return 0;
}
