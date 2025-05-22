#include <stdio.h>
#include <string.h>

// Global variable shared across all sessions
char user_id[100];

void handle_client_request(const char *session_id, const char *input_user_id)
{
    strcpy(user_id, input_user_id);
    printf("Session %s set user_id to %s\n", session_id, user_id);
}

void get_client_data(const char *session_id)
{
    printf("Session %s has user_id: %s\n", session_id, user_id);
}

int main()
{
    // Simulate two client sessions
    handle_client_request("session_1", "alice123");
    get_client_data("session_1"); // Correct: Shows alice123

    handle_client_request("session_2", "bob456");
    get_client_data("session_1"); // Vulnerable: Shows bob456 instead of alice123

    return 0;
}