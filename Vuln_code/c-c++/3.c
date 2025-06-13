#include <stdio.h>

int main()
{
    char buffer[5] = "test";                                     // Buffer of size 5 (4 chars + null terminator)
    int index = 10;                                              // Invalid index, beyond buffer size
    printf("Character at index %d: %c\n", index, buffer[index]); // Out-of-bounds read
    return 0;
}