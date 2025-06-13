#include <stdio.h>
#include <string.h>

void process_input()
{
    char buffer[10]; // Small buffer
    char format[50];

    printf("Enter your input: ");
    gets(buffer);

    char destination[20];
    strcpy(destination, buffer);

    sprintf(format, "Input was: %s", buffer);

    printf("%s\n", format);
}

int main()
{
    process_input();
    return 0;
}