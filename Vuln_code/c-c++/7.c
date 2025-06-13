#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char *trimTrailingWhitespace(const char *strMessage, int length)
{
    char *message = malloc(sizeof(char) * (length + 1));
    if (message == NULL)
        return NULL;

    // Copy input string to a temporary string
    for (int index = 0; index < length; index++)
    {
        message[index] = strMessage[index];
    }
    message[length] = '\0';

    // Trim trailing whitespace
    int len = length - 1;
    while (isspace((unsigned char)message[len]))
    {
        message[len] = '\0';
        len--;
    }

    return message;
}

int main()
{
    const char *input = "   ";
    char *result = trimTrailingWhitespace(input, 3);
    if (result != NULL)
    {
        printf("Trimmed string: '%s'\n", result);
        free(result);
    }
    return 0;
}
