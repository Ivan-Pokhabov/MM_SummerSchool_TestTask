#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HEADERS_NUMBER 10

#define OK 0
#define OPEN_FILE_ERROR -1
#define INCORRECT_ARGUMENTS -2
#define INCORRECT_FORMAT -3

int readBmp(char* fileName)
{
    int positions[HEADERS_NUMBER] = { 18, 22, 26, 28, 30, 34, 38, 42, 46, 50 };
    char* names[HEADERS_NUMBER] = { "Width", "Height", "Planes", "Bits/pixel", "Compression", "Image size",
                                    "Pixels/meter(Ox)", "Pixels/meter(Oy)", "Number of colours", "Important colours" };
    int sizeOfHeader[HEADERS_NUMBER] = { 4, 4, 2, 2, 4, 4, 4, 4, 4, 4 };

    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return OPEN_FILE_ERROR;
    }

    char format[3] = "";
    fread(format, sizeof(char), 2, file);
    if (strcmp(format, "BM") != 0)
    {
        printf("!%s!", format);
        return INCORRECT_FORMAT;
    }

    int value = 0;
    for (size_t i = 0; i < HEADERS_NUMBER; ++i)
    {
        fseek(file, positions[i], SEEK_SET);
        fread(&value, sizeOfHeader[i], 1, file);
        printf("%s: %d\n", names[i], value);
    }

    fclose(file);

    return OK;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        return INCORRECT_ARGUMENTS;
    }

    return readBmp(argv[1]);
}
