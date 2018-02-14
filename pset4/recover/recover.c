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
    uint8_t jpegEndBuffer[4] = {0xff, 0xd8, 0xff, 0xe1};
    uint8_t check[8];

    FILE* outputFile = NULL;
    while(fread(buffer, 512, 1, inputFile) > 0)
    {
        for(int i = 0; i < 4; i++)
		{
			check[i] = buffer[i];
		}

        if ((memcmp(jpegStartBuffer, check, 4) == 0 ) || (memcmp(jpegEndBuffer, check, sizeof(check)) == 0))
        {
            char newFileName[8];
            sprintf(newFileName, "%03d.jpg", count);

            if (outputFile == NULL)
            {
                outputFile = fopen(newFileName, "w");
                fwrite(buffer, sizeof(buffer), 1, outputFile);
            }
            else
            {
                fclose(outputFile);
                outputFile = fopen(newFileName, "w");
                fwrite(buffer, sizeof(buffer), 1, outputFile);
                count++;
            }
        }
        else
		{
			if(outputFile != NULL)
			{
				fwrite(buffer, sizeof(buffer), 1, outputFile);
			}
		}
    }
    if (outputFile != NULL)
    {
        fclose(outputFile);
    }
    fclose(inputFile);
}