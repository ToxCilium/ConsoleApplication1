#ifndef FILTER_H
#define FILTER_H

#include "catalog.h"

catalog** filter(catalog* array[], int size, bool (*check)(catalog* element), int& result_size);

/*
�������� ������� <function_name>:
    ������� ���������� ������ � ��������� ������� � ��� ��������� �� ��������,
    ��� ������� ������� ������ ���������� �������� true, ���������� � �����
    ������, ��������� �� ������� ������������ ��������

���������:
    array       - ������ � ��������� �������
    size        - ������ ������� � ��������� �������
    check       - ��������� �� ������� ������.
                  � �������� �������� ����� ��������� ����� �������� ���
                  ������� ������, �������� ������� ������� ����
    result_data - ��������, ������������ �� ������ - ����������, � �������
                  ������� ������� ������ ��������������� �������

������������ ��������
    ��������� �� ������ �� ���������� �� ��������, ��������������� �������
    ������ (��� ������� ������� ������ ���������� true)
*/


bool check_item_by_category(catalog* element);

/*
�������� ������� check_item_by_category:
    ������� ������ - ���������, �������� �� ������� ����������� � ��������� ����������

���������:
    element - ��������� �� �������, ������� ����� ���������

������������ ��������
    true, ���� ������� �������� �����������, � false � ���� ������
*/


bool check_item_by_price(catalog* element);

/*
�������� ������� check_item_by_price:
    ������� ������ - ���������, ��������� �� ���� ������� 100 ������

���������:
    element - ��������� �� �������, ������� ����� ���������

������������ ��������
    true, ���� ���� ���� 100 ������, � false � ���� ������
*/
int compare_by_count(catalog* first, catalog* second);

int compare_by_category(catalog* first, catalog* second);

int compare_by_category2(catalog* first, catalog* second);

void merge_sort(catalog* array[], int low, int high, int (*check)(catalog* first, catalog* second));

void selection_sort(catalog* array[], int size, int (*check)(catalog* first, catalog* second));

#endif