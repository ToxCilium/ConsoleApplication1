#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

#include "catalog.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
//#include "processing.h"

void output(catalog* subscription)
{
	/********** вывод цены **********/
	cout << "Цена........: ";
	// вывод цены
	cout << subscription->price << " ";
	cout << '\n';
	/********** вывод количества **********/
	cout << "Общее количество...........: ";
	// вывод количества
	cout << subscription->count << " ";
	cout << '\n';
	/********** вывод категории **********/
	cout << "Категория...........: ";
	// вывод категории
	cout << subscription->category << " ";
	cout << '\n';
	/********** вывод названия **********/
	cout << "Название...........: ";
	// вывод названия
	cout << subscription->title << " ";
	cout << '\n';
	cout << '\n';
}

int main()
{
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №1. GITi\n";
	cout << "Вариант №10. Католог товаров\n";
	cout << "Автор: Середа максим\n";
	cout << "Группа: 23ПИнж1з\n\n";
	catalog* subscriptions[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", subscriptions, size);
		cout << "***** Каталог товаров *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(subscriptions[i]);
		}
		bool (*check_function)(catalog*) = NULL; // check_function - это указатель на функцию, возвращающую значение типа bool,
														   // и принимающую в качестве параметра значение типа catalog*
		cout << "\nВыберите способ фильтрации или обработки данных:\n";
		cout << "1) Товары в категории промтовары\n";
		cout << "2) Товары с ценой выше 100 рублей\n";
		cout << "3) Сортировка слиянием по убыванию количества товаров" << '\n';
		cout << "4) Сортировка слиянием по возрастанию категории" << '\n';
		cout << "5) Сортировка выбором по убыванию количества товаров" << '\n';
		cout << "6) Сортировка выбором по возрастанию категории" << '\n';
		cout << "\nВведите номер выбранного пункта: ";
		int item;
		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:
			system("cls");
			check_function = check_item_by_category; // присваиваем в указатель на функцию соответствующую функцию
			cout << "***** Товары в категории промтовары *****\n\n";
			break;
		case 2:
			system("cls");
			check_function = check_item_by_price; // присваиваем в указатель на функцию соответствующую функцию
			cout << "***** Товары с ценой выше 100 рублей *****\n\n";
			break;
		case 3:
			system("cls");
			cout << "*****Сортировка слиянием по убыванию количества товара на складе*****" << '\n';
			merge_sort(subscriptions, 0, size - 1, compare_by_count);
			for (int i = 0; i < size; i++)
			{
				output(subscriptions[i]);
			}
			cout << '\n';
			cout << '\n';
			break;
		case 4:
			system("cls");
			cout << "*****Сортировка слиянием по возрастанию категории*****" << '\n';
			merge_sort(subscriptions, 0, size - 1, compare_by_category);
			for (int i = 0; i < size; i++)
			{
				output(subscriptions[i]);
			}
			cout << '\n';
			cout << '\n';
			break;
		case 5:
			system("cls");
			cout << "***** Сортировка выбором по убыванию количества товаров *****" << '\n';
			selection_sort(subscriptions, size, compare_by_count);
			for (int i = 0; i < size; i++)
			{
				output(subscriptions[i]);
			}
			cout << '\n';
			cout << '\n';
			break;
		case 6:
			system("cls");
			cout << "***** Сортировка выбором по возрастанию категории *****" << '\n';
			selection_sort(subscriptions, size, compare_by_category2);
			for (int i = 0; i < size; i++)
			{
				output(subscriptions[i]);
			}
			cout << '\n';
			cout << '\n';
			break;
		default:
			throw "Некорректный номер пункта";
		}
		if (check_function)
		{
			int new_size;
			catalog** filtered = filter(subscriptions, size, check_function, new_size);
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}
			delete[] filtered;
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
