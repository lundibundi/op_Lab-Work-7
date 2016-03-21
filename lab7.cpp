

//#include "C:\lundibundi\visual studio 2015\Projects\kpi\labs\labs\stdafx.h"
#include "C:\lundibundi\visual studio 2015\Projects\kpi\labs\labs\labs.h"

#include <conio.h>
#include <iostream>

char* read_line();
char* clean_repeat(char* string, bool clean_n);
void parse_string(char* input, const char* beg, const char* end);
char* str_to_contains(char* string, bool del, bool clean_n);
void parse_string_e(char* input, const char beg[256], const char end[256]);

int lab7()
{

	// read input
	char *beg, *end;
	std::cout << "enter beginning characters: ";
//	beg = clean_repeat(read_line(), true);
	beg = str_to_contains(read_line(), true, true);
	std::cout << "enter ending characters: ";
	end = str_to_contains(read_line(), true, true);
//	end = clean_repeat(read_line(), true);
	std::cout << "enter string: ";

	// ignore all that's left after previous input
	char* input = read_line();

	// parse string
//	parse_string(input, beg, end);
	parse_string_e(input, beg, end);

	delete[] input;
	delete[] end;
	delete[] beg;

	_getch();
	return 0;
}

void parse_string(char* input, const char* beg, const char* end)
{
	int len = strlen(input);
	if (input[len - 1] == '\n') input[len - 1] = '\0';

	const char* dels = " ,.-";
	char* token = NULL;
	char* word = strtok_s(input, dels, &token);
	while (word != NULL)
	{
		if (strchr(beg, *word) && strchr(end, word[strlen(word) - 1]))
		{
			std::cout << word << std::endl;
		}
		word = strtok_s(NULL, dels, &token);
	}
}

// beg and eng must be of length 256 and contain 1->true on characters that are present
void parse_string_e(char* input, const char beg[256], const char end[256])
{
	int len = strlen(input);
	if (input[len - 1] == '\n') input[len - 1] = '\0';

	const char* dels = " ,.-";
	char* token = NULL;
	char* word = strtok_s(input, dels, &token);
	while (word != NULL)
	{
		if (beg[*word] && end[word[strlen(word) - 1]])
		{
			std::cout << word << std::endl;
		}
		word = strtok_s(NULL, dels, &token);
	}
}

char* str_to_contains(char* string, bool del = false, bool clean_n = false)
{
	size_t len = strlen(string);
	char* seen = new char[256]{0};
	for (int i = 0; i < len; ++i)
	{
		seen[(unsigned)string[i]] = 1;
	}
	if (clean_n) seen[(unsigned) '\n'] = 0;
	if (del) delete[] string;
	return seen;
}

char* read_line()
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
