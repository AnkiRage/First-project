#include "BoolVector.h"

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

using Cell = unsigned char;
using UI = unsigned int;



BoolVector::BoolVector(int lenght){
	m_lenght = lenght;
	m_cellCount = m_lenght / cellSize;
	if (lenght % cellSize != 0)
		m_cellCount++;
	Vector = new Cell[m_cellCount];
}

BoolVector::BoolVector(const BoolVector& Other){
	m_cellCount = Other.m_cellCount;
	m_lenght = Other.m_lenght;
	Vector = new Cell[m_cellCount];
	for(int  i = 0; i < m_cellCount; i++){
		Vector[i] = Other.Vector[i];
	}
}

BoolVector::BoolVector(int lenght, bool value){
	m_lenght = lenght;
	m_cellCount = m_lenght / cellSize;
	if (lenght % cellSize != 0)
		m_cellCount++;
	Vector = new Cell[m_cellCount];
	Cell mask = 0;
	if (value)
		for(int i = 0, mask = 1; i < cellSize; i-- ){
			mask <<= 1;
			mask++;
		}
	for (int i = 0; i < m_cellCount; i++){
		Vector[i] = mask;
	}
}

BoolVector::BoolVector(char CharVector[], int lenght){
	Cell mask = 0;
	int flag = 0;
	m_lenght = lenght;
	m_cellCount = m_lenght / cellSize;
	if (lenght % cellSize != 0){
		m_cellCount++;
		flag = 1;
	}
	Vector = new Cell[m_cellCount];
	for (int i = 0; i < m_cellCount; i++){
		for (int g = 0, mask = 0; g < cellSize; g++){
			if (CharVector[i * cellSize + g ] == '1')
				mask++;
			mask <<= 1;
		}
		if(i == m_cellCount - 1 && flag == 1){
			int shift = m_lenght % cellSize;
			mask <<= (cellSize - shift);
		}
		Vector[i] = mask;
	}
}

BoolVector::~BoolVector(){
	delete[] Vector;
}

int BoolVector::Get_Lenght() const{
	return m_lenght;
}

void BoolVector::Swap_Vector(BoolVector& Other){
	Swap(m_lenght, Other.m_lenght);
	Swap(m_cellCount, Other.m_cellCount);
	Swap(Vector, Other.Vector);
}

void BoolVector::Inverse_All(){
	Cell mask = 1;
	for(int i = 0; i < cellSize - 1; i++ ){
			mask <<= 1;
			mask++;
	}
	for(int i = 0 ; i < m_cellCount; i++){
		Vector[i] ^= mask;
	}
}

void BoolVector::Inverse_Index(int index){
	if (index >= m_lenght)
	return;
	Cell mask = 1;
	int cellLocation = index / cellSize;
	if (index / cellSize != 0){
		cellLocation++;
	}
	mask <<= cellSize - (index % cellSize);
	Vector[cellLocation] ^= mask;
}

void BoolVector::Set_Index(int index, bool value){
	if (index >= m_lenght)
		return;
	Cell mask;
	int cellLocation = index / cellSize;
	if (index / cellSize != 0){
		cellLocation++;
	}
	if (value){
		mask = 1;
		mask <<= cellSize - (index % cellSize);
		Vector[cellLocation] |= mask;
	}
	else{
		mask = 0;
		for(int i = 0; i < cellSize -1 ; i++){
			if (i == (index %  cellSize -1)){
				mask <<= 1;
				continue;
			}
			mask++;
			mask <<= 1;
		}
		Vector[cellLocation] &= mask;
	}
}

void BoolVector::Set_Range(int start, int quantity, bool value){
	for(int  i = 0; i < quantity; i++){
		Set_Index(start + i, value);
	}
}

void BoolVector::Set_All(bool value){
	Cell mask;
	if (value){
		mask = 1;
		for(int i = 0; i < cellSize -1; i++){
		mask <<= 1;
		mask++;
		}
		for(int i = 0; i < m_cellCount; i++){
			Vector[i] |= mask;
		}
	}
	else{
		mask = 0;
		for(int i = 0; i < m_cellCount; i++){
			Vector[i] &= mask;
		}
	}
}

int BoolVector::Weight() const{
	int weight = 0;
	Cell mask = 0;
	for (int g = 0; g < m_cellCount; g++){
		for (int i = 0, mask = 1; i < cellSize - 1; i++){
			if (Vector[g] & mask)
				weight++;
			mask <<= 1;
		}
	}
	return weight;
}

void BoolVector::Print() const{
	int flag = 0;
	Cell mask = 0;
	if (m_lenght % cellSize != 0)
		flag = 1;
	for (int g = 0; g < m_cellCount; g++){
		mask = 1;
		mask <<= cellSize - 1;
		for (int i = 0; i < cellSize - 1; i++){
			if (Vector[g] & mask)
				cout << '1';
			else
				cout << '0';
			mask >>= 1;
			if (g == m_cellCount - 1 && flag == 1 && i == (m_lenght / cellSize -1))
				break;
		}
	}
}

BoolVector BoolVector::operator[](int index) const{

}
BoolVector BoolVector::operator&(const BoolVector& Other) const{
	if( m_lenght != Other.m_lenght) 
		return ;
	BoolVector Temp(*this);
	for(int i = 0; i < m_cellCount; i++){
		Temp.Vector[i] &= Other.Vector[i];
	}
	return Temp;
}

BoolVector& BoolVector::operator&=(const BoolVector& Other){
	if( m_lenght != Other.m_lenght) 
		return ;
	for(int i = 0; i < m_cellCount; i++){
		Vector[i] &= Other.Vector[i];
	}
	return *this;
}

BoolVector BoolVector::operator|(const BoolVector& Other) const{
	if( m_lenght != Other.m_lenght) 
		return ;
	BoolVector Temp(*this);
	for(int i = 0; i < m_cellCount; i++){
		Temp.Vector[i] |= Other.Vector[i];
	}
	return Temp;
}

BoolVector& BoolVector::operator|=(const BoolVector& Other){
	if( m_lenght != Other.m_lenght) 
		return ;
	for(int i = 0; i < m_cellCount; i++){
		Vector[i] |= Other.Vector[i];
	}
	return *this;
}

BoolVector BoolVector::operator^(const BoolVector& Other) const{
	if( m_lenght != Other.m_lenght) 
		return ;
	BoolVector Temp(*this);
	for(int i = 0; i < m_cellCount; i++){
		Temp.Vector[i] ^= Other.Vector[i];
	}
	return Temp;
}

BoolVector& BoolVector::operator^=(const BoolVector& Other){
	if( m_lenght != Other.m_lenght) 
		return ;
	for(int i = 0; i < m_cellCount; i++){
		Vector[i] ^= Other.Vector[i];
	}
	return *this;
}

BoolVector BoolVector::operator<<(const int shift) const{
	BoolVector Temp(*this);
	int flag = 0;
	if (Temp.m_lenght % Temp.cellSize != 0)
	flag = 1;
	int shiftCell = shift / cellSize;
	if (shiftCell >= Temp.m_cellCount){
		for( int i = 0; i < Temp.m_cellCount; i++){
		Temp.Vector[i] = 0;
		} 
	}
	else{
		for( int i = 0; i < Temp.m_cellCount - shiftCell; i++){
			Temp.Vector[i] = Temp.Vector[i + shiftCell];
		}
		for( int i = Temp.m_cellCount - shiftCell; i < Temp.m_cellCount; i++){
			Temp.Vector[i] = 0;
		}

	}
}

BoolVector& BoolVector::operator<<=(const int shift){
	
}
BoolVector BoolVector::operator>>(const int shift) const{
	
} 
BoolVector& BoolVector::operator>>=(const int shift){
	
}

BoolVector& BoolVector::operator~(){
	Inverse_All();
	return *this;
}

BoolVector& BoolVector::operator=(const BoolVector& Other){
	delete[] Vector;
	m_lenght = Other.m_lenght;
	m_cellCount = Other.m_cellCount;
	Vector = new Cell[m_cellCount];
	for (int i = 0; i < m_cellCount; i++){
		Vector[i] = Other.Vector[i];
	}
	return *this;
}







// UI Transent(char s[], int n)
// {
// 	UI x = 0; int i;
// 	for (i = 0; i < n; i++)
// 	{
// 		x <<= 1;
// 		if (s[i] == '1') {
// 			x++;
// 		}

// 	}
// 	return x;
// }

// void InputBM(UI* x, int m, int n)
// {
// 	char s[33];
// 	for (int i = 0; i < m; i++)
// 	{
// 		gets_s(s, 33);
// 		x[i] = Transent(s, n);
// 	}
// }

// void OutputBV(UI x, int n) {
// 	UI mask = 1 << (n - 1);
// 	for (int i = 0; i < n; i++, mask >>= 1) {
// 		if (x & mask) printf("1"); else printf("0");
// 	}
// }


// void OutputBM(UI* x, int m, int n) {
// 	for (int i = 0; i < m; i++) {
// 		OutputBV(x[i], n);
// 		printf("\n");
// 	}
// }


// int Weight1 (UI* x, int m, int n, int q){
// 	int w, i;
// 	UI mask = 1 << (n - q - 1) ;
// 	for (w = 0, i = 0; i < m; i++)
// 		if (x[i] & mask) w++;
// 	return w;
// }

// UI* Invert(UI* x, int m, int n, int q) {
// 	UI mask1 = 1 << (n - q - 1), mask2 = 1 << (n - (q + 1) - 1);   //или n - q -2
// 	//printf("\n");
// 	//OutputBV(mask1, n);
// 	//printf("\n");
// 	//OutputBV(mask2, n);
// 	//getchar();
// 	for (int i = 0; i < m; i++) {
// 		if (((mask1 & x[i]) >> (n - q - 1)) != ((mask2 & x[i]) >> (n - (q + 1) - 1))) {
// 			x[i] = x[i] ^ mask1;
// 			x[i] = x[i] ^ mask2;
// 		}
// 	}
// 	return x;
// }


// void Mark2(UI* x, int m, int n) {
// 	int count = n;
// 	UI* A;
// 	A = new UI[m];
// 	for (int i = 0; i < m; i++) {
// 		A[i] = x[i];
// 	}

// 	for (; count > 1; count --) {
// 		//printf("\ncount  = %d", count);
// 		for (int q = 0; (q + 1) < count ; q++) {
// 			if (Weight1(A, m, n, q) > Weight1(A, m, n, q + 1)) {
// 				//printf("\nq1 = %d", q);
// 				//printf("\nq2 = %d", q+1);
// 				A = Invert(A, m, n, q);
// 			}
// 		}
// 	}
// 	OutputBM(A, m, n);

// }