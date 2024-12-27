#include "BoolMatrix.h"

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

BoolMatrix::BoolMatrix(int cols, int rows){
	if( cols == 0 || rows == 0){
		cout << "Matrix can't be 0";
		return;
	}
	Matrix = new BoolVector[rows];
	for (int i = 0; i < rows; ++i)
	{
		Matrix[i] = BoolVector(cols, false);
	}
	m_cols = cols;
	m_rows = rows;
}
BoolMatrix::BoolMatrix(int cols, int rows, bool value){
	if( cols == 0 || rows == 0){
		cout << "Matrix can't be 0";
		return;
	}
	Matrix = new BoolVector[rows];
	for (int i = 0; i < rows; ++i)
	{
		Matrix[i] = BoolVector(cols, value);
	}
	m_cols = cols;
	m_rows = rows;
}
BoolMatrix::BoolMatrix(const BoolMatrix& Other){
	m_cols = Other.m_cols;
	m_rows = Other.m_rows;
	Matrix = new BoolVector[m_rows];
	for(int i = 0; i < m_rows; i++){
		Matrix[i] = Other.Matrix[i];
	}
}
BoolMatrix::BoolMatrix(char** CharVector, int cols, int rows){
	if( cols == 0 || rows == 0){
		cout << "Matrix can't be 0";
		return;
	}
	Matrix = new BoolVector[rows];
	m_cols = cols;
	m_rows = rows;
	for (int  i = 0; i < m_rows; i++){
		Matrix[i] = BoolVector(CharVector[i], m_cols);
	}
}
BoolMatrix::~BoolMatrix(){
	delete[] Matrix;
}

int BoolMatrix::Get_Cols() const{
	return m_cols;
}

int BoolMatrix::Get_Rows() const{
	return m_rows;
}

void BoolMatrix::Swap_Matrix(BoolMatrix& Other){
	Swap(m_cols, Other.m_cols);
	Swap(m_rows, Other.m_rows);
	Swap(Matrix, Other.Matrix);
}

int BoolMatrix::Weight_Matrix() const{
	int TempWeight = 0;
	for (int i = 0; i < m_rows; i++){
		TempWeight += Matrix[i].Weight();
	}
	return TempWeight;
}

BoolVector BoolMatrix::Mat_Conjuction() const{
	BoolVector Temp = Matrix[0];
	for (int i = 1; i < m_rows; i++){
		Temp &= Matrix[i];
	}
	return Temp;
}

BoolVector BoolMatrix::Mat_Disjunction() const{
	BoolVector Temp = Matrix[0];
	for (int i = 1; i < m_rows; i++){
		Temp |= Matrix[i];
	}
	return Temp;
}

int BoolMatrix::Weight_DefVector(int index) const{
	if(index < 0 || index >= m_rows)
		return 0;
	return Matrix[index].Weight();
}

void BoolMatrix::Inverse_BoolIndex(int index, int row){
	if(row < 0 || row >= m_rows || index < 0 || index >= m_cols)
		return;
	Matrix[row].Inverse_Index(index);
}

void BoolMatrix::Inverse_BoolRange(int start, int quantity, int row){
	if (row < 0 || row >= m_rows || start < 0 || start >= m_cols)
		return;
	for (int i = 0; i < quantity && i < m_cols; i++){
	Matrix[row].Inverse_Index(start + i);
	}
}

void BoolMatrix::Set_BoolIndex(int index, int row, bool value){
	if (row < 0 || row >= m_rows || index < 0 || index > m_cols)
		return;
	Matrix[row].Set_Index(index, value);
}

void BoolMatrix::Set_BoolRange(int start, int quantity, int row, bool value){
	if (row < 0 || row >= m_rows || start < 0 || start >= m_cols)
		return;
	for( int i = 0; i < quantity && i < m_cols; i++){
		Matrix[row - 1].Set_Index(start + quantity, value);
	}
}

BoolMatrix& BoolMatrix::operator=(const BoolMatrix& Other){
	delete[] Matrix;
	m_cols = Other.m_cols;
	m_rows = Other.m_rows;
	Matrix = new BoolVector[m_rows];
	for(int i = 0; i < m_rows; i++){
		Matrix[i] = Other.Matrix[i];
	}
	return *this;
}

BoolVector& BoolMatrix::operator[](int index) const{
	return Matrix[index];
}

BoolVector& BoolMatrix::operator[](int index){
	return Matrix[index];
}

BoolMatrix BoolMatrix::operator&(const BoolMatrix& Other) const{
	BoolMatrix Temp(*this);
	Temp &= Other;
	return Temp;
}

BoolMatrix& BoolMatrix::operator&=(const BoolMatrix& Other){
	for( int i = 0; i < m_rows; i++){
		Matrix[i] &= Other.Matrix[i];
	}
	return *this;
}

BoolMatrix BoolMatrix::operator|(const BoolMatrix& Other) const{
	BoolMatrix Temp(*this);
	Temp |= Other;
	return Temp;
}

BoolMatrix& BoolMatrix::operator|=(const BoolMatrix& Other){
	for( int i = 0; i < m_rows; i++){
		Matrix[i] |= Other.Matrix[i];
	}
	return *this;
}

BoolMatrix BoolMatrix::operator^(const BoolMatrix& Other) const{
	BoolMatrix Temp(*this);
	Temp ^= Other;
	return Temp;
}

BoolMatrix& BoolMatrix::operator^=(const BoolMatrix& Other){
	for( int i = 0; i < m_rows; i++){
		Matrix[i] ^= Other.Matrix[i];
	}
	return *this;
}

BoolMatrix BoolMatrix::operator~()const{
	BoolMatrix Temp(*this);
	for( int i = 0; i < m_rows; i++){
		Temp.Matrix[i].Inverse_All();
	}
	return Temp;
}

ostream& operator<<(ostream& os, const BoolMatrix& Matrix){
	for (int i = 0 ; i < Matrix.Get_Rows(); i++){
		os << "| " << Matrix[i] << " |\n";
	}
	return os;
}

istream& operator>>(istream& is, BoolMatrix& Matrix){
	char bit;
	for (int i = 0 ; i < Matrix.Get_Rows(); i++){
		for( int g = 0; g < Matrix.Get_Cols(); g++){
			is >> bit;
			if (bit == '1')
				Matrix[i].Set_Index(g, 1);
			else
				Matrix[i].Set_Index(g, 0);
		}
	}
	return is;
}
