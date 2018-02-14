#include <stdio.h>
#include <cs50.h>
#include <stdint.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("%s file.raw\n", argv[0]);
        return 1;
    }

    string fileName = argv[1];
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL)
    {
        printf("Unable to open file %s", fileName);
        return 2;
    }

    int count = 0;
    int open = 0;
    FILE *outputFile;

    uint8_t buffer[512];
    uint8_t jpegStartBuffer[4] = {0xff, 0xd8, 0xff, 0xe0};
    uint8_t jpegEndBuffer[4] = {0xff, 0xd8, 0xff, 0xe1};
    uint8_t check[4];
    fread(buffer, 512, 1, inputFile);

    while (fread(buffer, 512, 1, inputFile) > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            check[i] = buffer[i];
        }

        if ((memcmp(jpegStartBuffer, check, 4) == 0 ) || (memcmp(jpegEndBuffer, check, sizeof(check)) == 0))
        {
            char filename[8];
            sprintf(filename, "%03d.jpg", count);

            if (open == 0)
            {
                outputFile = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, outputFile);
                open = 1;
            }
            if (open == 1)
            {
                fclose(outputFile);
                outputFile = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, outputFile);
                count++;
            }
        }
        else
        {
            if (open == 1)
            {
                fwrite(buffer, sizeof(buffer), 1, outputFile);
            }
        }
    }
    if (outputFile)
    {
        fclose(outputFile);
    }
    fclose(inputFile);
}