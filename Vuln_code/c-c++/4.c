#include <stdio.h>
#include <string.h>

void process_user_data(int index, char value)
{
    // This variable is meant to control access. 0 = regular user, 1 = admin.
    int is_admin = 0;

    // A data buffer for user operations.
    char user_buffer[10];

    printf("Before operation:\n");
    printf("  is_admin flag = %d\n", is_admin);
    printf("  Address of is_admin = %p\n", &is_admin);
    printf("  Address of user_buffer start = %p\n", &user_buffer[0]);
    printf("----------------------------------------\n");

    // THE VULNERABLE CODE
    // The program trusts the 'index' provided by the user without validation.
    // An attacker can provide a negative index to write outside the buffer's bounds.
    user_buffer[index] = value;

    printf("After operation:\n");
    printf("  is_admin flag = %d\n", is_admin);

    // Check if the user has successfully gained admin privileges
    if (is_admin == 1)
    {
        printf("\n[!!!] Access Granted: You are now an administrator! [!!!]\n");
    }
    else
    {
        printf("\n[-] Access Denied: You are a regular user.\n");
    }
}

int main()
{
    printf("--- Scenario 1: Normal Operation ---\n");
    // A normal operation writes inside the buffer.
    process_user_data(5, 'A');

    printf("\n\n--- Scenario 2: Attack --- \n");
    // An attacker provides a negative index to trigger the underwrite.
    // The exact index (-4, -8, etc.) depends on the compiler and system architecture.
    // We are trying to overwrite the 'is_admin' variable.
    process_user_data(-4, 1);

    return 0;
}