#include "constants.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "file_reader.h"

date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, " ", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, " ", &context);
    result.month = atoi(str_number);
    return result;
}

void read(const char* file_name, wind_data* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        while (!file.eof() && size < MAX_FILE_ROWS_COUNT)
        {
            wind_data* item = new wind_data;
            file >> item->wind_date.day >> item->wind_date.month;
            file >> item->wind_direction >> item->wind_spaad;
            file >> item->wind_spaad, MAX_STRING_SIZE;
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}