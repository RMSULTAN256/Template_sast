#include <stdio.h>
#include <stdlib.h>

void parseFile(const unsigned char *data, size_t length)
{
    if (length < 1)
    {
        printf("File too short!\n");
        return;
    }

    unsigned char numSections = data[0];
    printf("Sections to read: %d\n", numSections);

    for (int i = 0; i <= numSections; i++)
    { // ❌ CWE-788: off-by-one
        // Each section is 4 bytes
        size_t offset = 1 + i * 4;
        if (offset + 3 >= length)
        {
            printf("Unexpected end of file!\n");
            return;
        }

        int value = (data[offset] << 24) | (data[offset + 1] << 16) |
                    (data[offset + 2] << 8) | data[offset + 3];
        printf("Section %d: Value = %d\n", i, value);
    }
}

int main()
{
    unsigned char fileData[] = {
        2,          // number of sections
        0, 0, 0, 1, // section 1
        0, 0, 0, 2  // section 2
        // no section 3!
    };
    parseFile(fileData, sizeof(fileData));
    return 0;
}
