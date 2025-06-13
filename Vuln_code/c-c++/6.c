#include <stdio.h>
#include <string.h>

void process_data(char *user_input)
{
    char dest_buffer[50]; // Destination buffer is small.

    printf("Processing user data...\n");

    // VULNERABLE LINE: This line will be matched by the regex.
    // It copies 'user_input' into 'dest_buffer' using the length of the source ('user_input').
    // If 'user_input' is longer than 49 characters, this will write out of bounds.
    strncpy(dest_buffer, user_input, strlen(user_input));

    printf("Data processed: %s\n", dest_buffer);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }
    // An attacker provides a string longer than 50 characters to cause an overflow.
    process_data(argv[1]);
    return 0;
}