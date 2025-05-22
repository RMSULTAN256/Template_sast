#include <stdio.h>
#include <string.h>

void process_input() {
    char buffer[10];  // Small buffer
    char format[50];

    // CWE-242: gets does not check input size, can overflow buffer
    printf("Enter your input: ");
    gets(buffer);  // Dangerous: No bounds checking

    // CWE-242: strcpy does not check destination buffer size
    char destination[20];
    strcpy(destination, buffer);  // Dangerous: Can overflow if buffer is too large

    // CWE-242: sprintf does not check destination buffer size
    sprintf(format, "Input was: %s", buffer);  

    printf("%s\n", format);
}

int main() {
    process_input();
    return 0;
}