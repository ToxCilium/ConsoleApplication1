#ifndef FILTER_H
#define FILTER_H

#include "catalog.h"

catalog** filter(catalog* array[], int size, bool (*check)(catalog* element), int& result_size);

/*
ОПИСАНИЕ ФУНКЦИИ <function_name>:
    функция перебирает массив с исходными данными и все указатели на элементы,
    для которых функция отбора возвращает значение true, помещаются в новый
    массив, указатель на который возвращается функцией

ПАРАМЕТРЫ:
    array       - массив с исходными данными
    size        - размер массива с исходными данными
    check       - указатель на функцию отбора.
                  В качестве значения этого параметра можно передать имя
                  функции отбора, прототип которой приведён ниже
    result_data - параметр, передаваемый по ссылке - переменная, в которую
                  функция запишет размер результирующего массива

ВОЗВРАЩАЕМОЕ ЗНАЧЕНИЕ
    указатель на массив из указателей на элементы, удовлетворяющие условию
    отбора (для которых функция отбора возвращает true)
*/


bool check_item_by_category(catalog* element);

/*
ОПИСАНИЕ ФУНКЦИИ check_item_by_category:
    функция отбора - проверяет, является ли предмет относящимся к категории промтовары

ПАРАМЕТРЫ:
    element - указатель на элемент, который нужно проверить

ВОЗВРАЩАЕМОЕ ЗНАЧЕНИЕ
    true, если предмет является промтоваром, и false в ином случае
*/


bool check_item_by_price(catalog* element);

/*
ОПИСАНИЕ ФУНКЦИИ check_item_by_price:
    функция отбора - проверяет, превышает ли цена предмет 100 рублей

ПАРАМЕТРЫ:
    element - указатель на элемент, который нужно проверить

ВОЗВРАЩАЕМОЕ ЗНАЧЕНИЕ
    true, если цена выше 100 рублей, и false в ином случае
*/
int compare_by_count(catalog* first, catalog* second);

int compare_by_category(catalog* first, catalog* second);

int compare_by_category2(catalog* first, catalog* second);

void merge_sort(catalog* array[], int low, int high, int (*check)(catalog* first, catalog* second));

void selection_sort(catalog* array[], int size, int (*check)(catalog* first, catalog* second));

#endif