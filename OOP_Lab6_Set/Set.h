#pragma once

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>

#include "../OOP_Lab3_BoolVector/BoolVector.h"

using std::cout;
using std::cin;
using std::ostream;
using std::istream;

static const int cellSize = 8;


class CharSet : public BoolVector {
public:
    CharSet();
    CharSet(char* CharArray);
	CharSet(const CharSet& Other);
	~CharSet();

	int CharSet_Weight();
	bool Find_Elem(char elem);
	char Find_Min();
	char Find_Max();

	CharSet& operator=(const CharSet& Other);
	bool operator==(const CharSet& Other);
	bool operator!=(const CharSet& Other);
	CharSet& operator+=(const char& element);
	CharSet operator+(const char& element);
	CharSet& operator-=(const char& element);
	CharSet operator-(const char& element);
	CharSet& operator|=(const CharSet& Other); /// Объединение
	CharSet operator|(const CharSet& Other);
	CharSet& operator&=(const CharSet& Other); /// Перечесение
	CharSet operator&(const CharSet& Other);
	CharSet& operator/=(const CharSet& Other); /// Разность
	CharSet operator/(const CharSet& Other);
	CharSet operator~();
};

ostream& operator<<(ostream& os, const CharSet& Set);
istream& operator>>(istream& is, CharSet& Set);