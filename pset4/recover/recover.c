#include <stdio.h>
#include <cs50.h>
#include <stdint.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    if(argc != 2)
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
    uint8_t buffer[512];
    uint8_t jpegStartBuffer[4] = {0xff, 0xd8, 0xff, 0xe0};

    FILE* outputFile = NULL;
    while(fread(buffer, 1, 512, inputFile) == 512)
    {
        if (memcmp(buffer, jpegStartBuffer, 4) == 0)
        {
            char newFileName[8];
            sprintf(newFileName, "%03d.jpg", count);

            if (outputFile == NULL)
            {
                outputFile = fopen(newFileName, "w");
                fwrite(buffer, sizeof(buffer), 512, outputFile);
            }
            else
            {
                fclose(outputFile);
                outputFile = fopen(newFileName, "w");
                fwrite(buffer, sizeof(buffer), 512, outputFile);
                count++;
            }
        }
    }
    if (outputFile != NULL)
    {
        fclose(outputFile);
    }
    fclose(inputFile);
}