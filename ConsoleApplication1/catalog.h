#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constants.h"

struct catalog
{
	float price;
	int count;
	char category[MAX_STRING_SIZE];
	char title[MAX_STRING_SIZE];
};

#endif
