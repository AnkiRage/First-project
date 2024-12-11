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
using Cell = unsigned char;

template <typename Type>
void Swap(Type& A, Type& B)
{
	Type Buff = A;
    A = B;
    B = Buff;
}

static const int cellSize = 8;

class BoolMatrix{
public:
	class BoolVector;

	BoolMatrix(int lenght = cellSize, int rows = 1);
	BoolMatrix(int lenght, int rows, bool value);
	BoolMatrix(const BoolMatrix& Other);
	BoolMatrix(char* CharVector[], int lenght, int rows);
	~BoolMatrix();

	int Get_Lenght() const;
	int Get_Rows() const;
	void Swap_Matrix(BoolMatrix& Other);
	int Weight_Matrix() const;
	BoolVector Mat_Conjuction();
	BoolVector Mat_Disjunction();
	int Weight_DefVector(int index) const;
	void Inverse_MatIndex(int index, int row);
	void Inverse_MatRange(int start, int quantity, int row);
	void Set_MatIndex(int index, int row, bool value);
	void Set_MatRange(int start, int quantity, int row, bool value);

	BoolMatrix& operator=(const BoolMatrix& Other);
	BoolVector operator[](int index) const;
	

	int test();


private:
	BoolVector* Matrix;
	int m_rows;
	int m_Matlenght;
	int m_MatcellCount;
};


class BoolMatrix::BoolVector
{
public:
	

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
	int Weight_Vector() const;
	void Print() const;

	bool operator[](int index) const;
	BoolVector& operator[](int index);
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

ostream& operator<<(ostream& os, const BoolMatrix::BoolVector& Arr){
	os << '{';
	Arr.Print();
	os << '}';
	return os;
}
istream& operator>>(ostream& is, const BoolMatrix::BoolVector& Arr){
	
}