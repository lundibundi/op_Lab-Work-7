

//#include "C:\lundibundi\visual studio 2015\Projects\kpi\labs\labs\stdafx.h"
#include "C:\lundibundi\visual studio 2015\Projects\kpi\labs\labs\labs.h"

#include <conio.h>
#include <iostream>

char* read_input()
{
	int size = 256, old_size = 0;
	char* buf = new char[size]{0};
	fgets(buf, size, stdin);
	// magically after reaching \n fgets sets all characters after \n\0 to char(-2) ?
	while (buf[size - 2] != '\n' && buf[size - 2] != '\0' && buf[size - 2] != -2)
	{
		old_size = size;
		size *= 2;
		char* new_buf = new char[size]{0};
		strncpy_s(new_buf, size, buf, old_size);
		delete[] buf;
		buf = new_buf;
		fgets(buf + old_size - 1, size - old_size + 1, stdin);
	}
	return buf;
}

int lab7()
{
	// read input
	char beg, end;
	std::cout << "enter beginning character: ";
	std::cin >> beg;
	std::cout << "enter ending character: ";
	std::cin >> end;
	char* input = read_input();
	std::cout << input;
	// parse string
//	parse_string(input, beg, end);

	_getch();
	return 0;
}
