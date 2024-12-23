#pragma once

#include <iostream>
#include <cmath>
#include <time.h>
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

	BoolMatrix(int lenght = cellSize, int rows = 1);
	BoolMatrix(int lenght, int rows, bool value);
	BoolMatrix(const BoolMatrix& Other);
	BoolMatrix(char** CharVector, int lenght, int rows);
	~BoolMatrix();

	int Get_Cols() const;
	int Get_Rows() const;
	void Swap_Matrix(BoolMatrix& Other);
	int Weight_Matrix() const;
	BoolVector Mat_Conjuction() const;
	BoolVector Mat_Disjunction() const;
	int Weight_DefVector(int index) const;
	void Inverse_BoolIndex(int index, int row);
	void Inverse_BoolRange(int start, int quantity, int row);
	void Set_BoolIndex(int index, int row, bool value);
	void Set_BoolRange(int start, int quantity, int row, bool value);

	BoolMatrix& operator=(const BoolMatrix& Other);
	BoolVector& operator[](int index) const;
	BoolVector& operator[](int index);
	BoolMatrix operator&(const BoolMatrix& Other) const;
	BoolMatrix& operator&=(const BoolMatrix& Other);
	BoolMatrix operator|(const BoolMatrix& Other) const;
	BoolMatrix& operator|=(const BoolMatrix& Other);
	BoolMatrix operator^(const BoolMatrix& Other) const;
	BoolMatrix& operator^=(const BoolMatrix& Other);
	BoolMatrix operator~()const;


	
private:
	BoolVector* Matrix;
	int m_rows;
	int m_cols;
};

ostream& operator<<(ostream& os, const BoolMatrix& Matrix);
istream& operator>>(istream& is, BoolMatrix& Matrix);