#include "filter.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int compare_by_count(catalog* first, catalog* second)
{
    int first_count = first->count;
    int second_count = second->count;
    return first_count < second_count;
}

int compare_by_category2(catalog* first, catalog* second)
{
    string first_discipline = first->category;
    string second_discipline = second->category;
    if (second_discipline.compare(first_discipline) == 0) {
        float first_price = first->price;
        float second_price = second->price;
        return first_price > second_price;
    }
    return second_discipline.compare(first_discipline);
}
int compare_by_category(catalog* first, catalog* second)
{
    string first_discipline = first->category;
    string second_discipline = second->category;
    if (first_discipline.compare(second_discipline) == 0) {
        float first_price = first->price;
        float second_price = second->price;
        return first_price < second_price;
    }
    return first_discipline.compare(second_discipline);
}
void merge(catalog* arr[], int l, int m, int r, int (*check)(catalog* first, catalog* second)) {
    int n1 = m - l + 1;
    int n2 = r - m;

    catalog** L = new catalog * [n1];
    catalog** R = new catalog * [n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;

    int k = l;
    while (i < n1 && j < n2) {
        if (check(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}


catalog** filter(catalog* array[], int size, bool (*check)(catalog* element), int& result_size)
{
	catalog** result = new catalog * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_item_by_category(catalog* element)
{
	return strcmp(element->category, "ןנמלעמגאנû") == 0;
}

bool check_item_by_price(catalog* element)
{
	return element->price >= 100;
}

void merge_sort(catalog* array[], int l, int r, int (*check)(catalog* first, catalog* second)) {
	if (l < r) {
		int m = l + (r - l) / 2;
		merge_sort(array, l, m, check);
		merge_sort(array, m + 1, r, check);
		merge(array, l, m, r, check);
	}
}
void selection_sort(catalog* array[], int size, int (*check)(catalog* first, catalog* second)) {
    catalog* stool;
    int key;
    for (int i = 0; i < size; i++) {
        key = i;
        for (int j = i + 1;j < size; j++)
        {
            if (check(array[j], array[key]) > 0)
            {
                key = j;
            }
        }
        if (i != key)
        {
            stool = array[i];
            array[i] = array[key];
            array[key] = stool;
        }
        
    }
}
