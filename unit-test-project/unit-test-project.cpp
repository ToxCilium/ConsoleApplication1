#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/catalog.h"
#include "../ConsoleApplication1/processing.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{

	catalog* build_subscription(float price, int count, char category[MAX_STRING_SIZE], char title[MAX_STRING_SIZE])
	{
		catalog* subscription = new catalog;
		subscription->price = price;
		subscription->count = count;
		strcpy_s(subscription->category, category);
		strcpy_s(subscription->title, title);
		return subscription;
	}

	void delete_subscription(catalog* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			catalog* subscriptions[3];
			subscriptions[0] = build_subscription(230.20, 20, "promtov", "Зеленка"); // 5 
			subscriptions[1] = build_subscription(230.12, 20, "promtov", "Зеленка");
			subscriptions[2] = build_subscription(230.20, 20, "promtov", "Зеленка"); // 4 
			float max = 0;
			for (int i = 0; i < 3; i++)
			{
				max += subscriptions[i]->price;
			}

			Assert::AreEqual(max, process(subscriptions, 3, "promtov"));
			delete_subscription(subscriptions, 3);

		}
		TEST_METHOD(TestMethod2)
		{
			catalog* subscriptions[3];
			subscriptions[0] = build_subscription(230.20, 20, "promtov", "Зеленка"); // 5 
			subscriptions[1] = build_subscription(230.12, 20, "promtov", "Зеленка");
			subscriptions[2] = build_subscription(230.20, 20, "promtov", "Зеленка");// 4
			
			char cat[MAX_STRING_SIZE] = "promtov";
			int test = strcmp(subscriptions[0]->category,cat);
			Assert::AreEqual(0, test);
			delete_subscription(subscriptions, 3);

		}
		TEST_METHOD(TestMethod3)
		{
			catalog* subscriptions[3];
			subscriptions[0] = build_subscription(230.20, 20, "promtov", "Зеленка"); // 5 
			subscriptions[1] = build_subscription(230.12, 20, "promtov", "Зеленка");
			subscriptions[2] = build_subscription(230.20, 20, "promtov", "Зеленка");// 4
			char cat[MAX_STRING_SIZE] = "promtov";
			int test = strcmp(subscriptions[0]->category, cat);
			Assert::AreEqual(20, subscriptions[0]->count);
			delete_subscription(subscriptions, 3);

		}
	};
}
