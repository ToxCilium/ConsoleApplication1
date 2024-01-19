#include "processing.h"
#include <string>

using namespace std;


float process(catalog* array[], int size, char category[MAX_STRING_SIZE])
{
	float max = 0;
	for (int i = 1; i < size; i++)
	{
		if (strcmp(array[i]->category,category)==0)
		{
			max += array[i]->price;
		}
	}
	return max;
}