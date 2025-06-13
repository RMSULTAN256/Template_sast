#include <stdio.h>
#include <string.h>
#include <stdint.h> // For uintptr_t

char *getPayload(char *packetBuffer, int packetSize, int headerOffset)
{

    char *headerPtr = packetBuffer + headerOffset;
    int payloadOffset = *((int *)headerPtr);

    char *payloadPtr = headerPtr + payloadOffset;

    printf("Debug: Calculated payload address: %p\n", payloadPtr);

    if (payloadPtr >= packetBuffer + packetSize)
    {
        printf("Error: Payload is out of bounds (too high)!\n");
        return NULL;
    }

    return payloadPtr;
}
int main()
{
    char packet[128];
    memset(packet, 0, sizeof(packet));

    printf("Info: Packet buffer starts at address: %p\n", (void *)packet);

    int headerStartsAt = 32;

    int maliciousOffset = -48;
    memcpy(packet + headerStartsAt, &maliciousOffset, sizeof(int));

    char *payload = getPayload(packet, sizeof(packet), headerStartsAt);

    if (payload)
    {
        printf("Vulnerability triggered. Payload pointer is at: %p\n", (void *)payload);
    }

    return 0;
}