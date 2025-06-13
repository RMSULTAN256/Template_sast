#include <stdio.h>
#include <string.h>

void vulnerable_function(const char *input)
{
    char buffer[10];
    strcpy(buffer, input); // No bounds checking!
    printf("Buffer contains: %s\n", buffer);
}

int main()
{
    char *user_input = "This input is definitely more than 10 characters!";
    vulnerable_function(user_input);
    return 0;
}
