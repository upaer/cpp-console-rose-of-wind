#include <iostream>
#include "rose-of-wind.h"
#include "file_reader.h"
#include "constants.h"
#include <algorithm>

int compareDecreasingWindSpeed(const void* a, const void* b) {
    return (*(wind_data**)b)->wind_spaad - (*(wind_data**)a)->wind_spaad;
}

int compareIncreasingWindDirection(const void* a, const void* b) {
    if ((*(wind_data**)a)->wind_direction != (*(wind_data**)b)->wind_direction) {
        return (*(wind_data**)a)->wind_direction - (*(wind_data**)b)->wind_direction;
    }
    else if ((*(wind_data**)a)->wind_date.month != (*(wind_data**)b)->wind_date.month) {
        return (*(wind_data**)a)->wind_date.month - (*(wind_data**)b)->wind_date.month;
    }
    else {
        return (*(wind_data**)a)->wind_date.day - (*(wind_data**)b)->wind_date.day;
    }
}

void shakerSort(wind_data* arr[], int size, int (*compare)(const void*, const void*)) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (compare(&arr[i], &arr[i + 1]) > 0) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;

        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (compare(&arr[i], &arr[i + 1]) > 0) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void mergeSort(wind_data* arr[], int size, int (*compare)(const void*, const void*)) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;

    mergeSort(arr, mid, compare);
    mergeSort(arr + mid, size - mid, compare);

    std::inplace_merge(arr, arr + mid, arr + size, compare);
}

int main() {
    std::cout << "Laboratory work #8. GITn";
    std::cout << "Variant #6. Rose of windn";
    std::cout << "Author: Dmitry Mamoikon";
    std::cout << "Group: 23PInj1D_1n";
    wind_data* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++) {
            std::cout << subscriptions[i]->wind_date.day << "  ";
            std::cout << subscriptions[i]->wind_date.month << "  ";
            std::cout << subscriptions[i]->wind_spaad << "  ";
            std::cout << subscriptions[i]->wind_direction << "  ";
            std::cout << 'n';
        }

        for (int i = 0; i < size; i++) {
            delete subscriptions[i];
        }
    }
    catch (const char* error) {
        std::cout << error << 'n';
    }
    return 0;
}
