#include <iostream>
#include <string>

void print_chars(const char *str)
{
    for (int i = 0; i <= 100; i++)
    { // Fixed loop limit, no bounds check
        std::cout << "Character " << i << ": " << str[i] << std::endl;
    }
}

int main()
{
    std::string input = "short";
    print_chars(input.c_str());
    return 0;
}