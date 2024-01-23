#include "process.h"

#include "rose-of-wind.h"
#include <iostream>
using namespace std;

float monthly_prepositions(wind_data* subscriptions[], int size, int month)
{

	float sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (subscriptions[i]->wind_date.month == month)
		{
			sum += subscriptions[i]->wind_spaad;
		}
	}
	cout << "Your monthly prepositions are equal to " << sum << endl;
	return sum;
}