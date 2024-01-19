#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>


void read(const char* file_name, catalog* array[], int& size)
{
	std::ifstream file(file_name);
	if (file.is_open())
	{
		size = 0;
		char tmp_buffer[MAX_STRING_SIZE];
		while (!file.eof())
		{
			catalog* item = new catalog;
			file >> item->price;
			file >> item->count;
			file >> item->category;
			file.read(tmp_buffer, 1); // чтения лишнего символа пробела
			file.getline(item->title, MAX_STRING_SIZE);
			array[size++] = item;
		}
		file.close();
	}
	else
	{
		throw "Ошибка открытия файла";
	}
}
