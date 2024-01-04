#ifndef ROSE_OF_WIND_H
#define ROSE_OF_WIND_H

#include "constants.h"

struct date
{
    int day;
    int month;
};

struct wind_data
{
    date wind_date;
    float wind_spaad;
    char wind_direction[MAX_STRING_SIZE];
};

#endif
