#include <iostream>
#include "rose-of-wind.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main()
{
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #6. Rose of wind\n";
    cout << "Author: Dmitry Mamoiko\n";
    wind_data* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->wind_date.day << "  ";
            cout << subscriptions[i]->wind_date.month << "  ";
            cout << subscriptions[i]->wind_spaad << "  ";
            cout << subscriptions[i]->wind_direction << "  ";
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}