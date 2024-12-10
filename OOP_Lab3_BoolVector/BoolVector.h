#pragma once

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;

using UI = unsigned int;



class BoolVector
{
using Cell = unsigned char;

template <typename Type>
void Swap(Type& A, Type& B)
{
	Type Buff = A;
    A = B;
    B = Buff;
}

public:
	static const int cellSize = 8;

	BoolVector(int lenght = cellSize);
	BoolVector(const BoolVector& Other);
	BoolVector(int lenght, bool value);
	BoolVector(char CharVector[], int leght);
	~BoolVector();

	int Get_Lenght() const;
	void Swap_Vector(BoolVector& Other);
	void Inverse_All();
	void Inverse_Index(int index);
	void Set_Index(int index, bool value);
	void Set_Range(int start, int quantity, bool value);
	void Set_All(bool value);
	int Weight() const;
	void Print() const;

	BoolVector operator[](int index) const;
	BoolVector operator&(const BoolVector& Other) const; ///// Bool AND
	BoolVector& operator&=(const BoolVector& Other);
	BoolVector operator|(const BoolVector& Other) const; ///// Bool OR
	BoolVector& operator|=(const BoolVector& Other);
	BoolVector operator^(const BoolVector& Other) const; ///// Bool XOR
	BoolVector& operator^=(const BoolVector& Other);
	BoolVector operator<<(const int shift) const; ///// Bool Shift
	BoolVector& operator<<=(const int shift);
	BoolVector operator>>(const int shift) const; 
	BoolVector& operator>>=(const int shift);
	BoolVector operator~();
	BoolVector& operator=(const BoolVector& Other);

	



private:
	Cell* Vector;
	int m_lenght;
	int m_cellCount;
};

ostream& operator<<(ostream& os, const BoolVector& Arr);
istream& operator>>(ostream& is, const BoolVector& Arr);

void Mark2(UI* x, int m, int n);
UI* Invert(UI* x, int m, int n, int q);
int Weight1 (UI* x, int m, int n, int q);
void OutputBM(UI* x, int m, int n);
void OutputBV(UI x, int n);
void InputBM(UI* x, int m, int n);
UI Transent (char s[], int n);
