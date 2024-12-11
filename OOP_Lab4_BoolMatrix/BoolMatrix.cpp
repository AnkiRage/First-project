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

using Cell = unsigned char;
using UI = unsigned int;


int BoolMatrix::test(){

}










//////////////////VECTOR/////////////////////
BoolMatrix::BoolVector::BoolVector(int lenght){
	m_lenght = lenght;
	m_cellCount = m_lenght / cellSize;
	if (lenght % cellSize != 0)
		m_cellCount++;
	Vector = new Cell[m_cellCount];
}

BoolMatrix::BoolVector::BoolVector(const BoolVector& Other){
	m_cellCount = Other.m_cellCount;
	m_lenght = Other.m_lenght;
	Vector = new Cell[m_cellCount];
	for(int  i = 0; i < m_cellCount; i++){
		Vector[i] = Other.Vector[i];
	}
}

BoolMatrix::BoolVector::BoolVector(int lenght, bool value){
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

BoolMatrix::BoolVector::BoolVector(char CharVector[], int lenght){
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

BoolMatrix::BoolVector::~BoolVector(){
	delete[] Vector;
}

int BoolMatrix::BoolVector::Get_Lenght() const{
	return m_lenght;
}

void BoolMatrix::BoolVector::Swap_Vector(BoolVector& Other){
	Swap(m_lenght, Other.m_lenght);
	Swap(m_cellCount, Other.m_cellCount);
	Swap(Vector, Other.Vector);
}

void BoolMatrix::BoolVector::Inverse_All(){
	Cell mask = 1;
	for(int i = 0; i < cellSize - 1; i++ ){
			mask <<= 1;
			mask++;
	}
	for(int i = 0 ; i < m_cellCount; i++){
		Vector[i] ^= mask;
	}
}

void BoolMatrix::BoolVector::Inverse_Index(int index){
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

void BoolMatrix::BoolVector::Set_Index(int index, bool value){
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

void BoolMatrix::BoolVector::Set_Range(int start, int quantity, bool value){
	for(int  i = 0; i < quantity; i++){
		Set_Index(start + i, value);
	}
}

void BoolMatrix::BoolVector::Set_All(bool value){
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

int BoolMatrix::BoolVector::Weight_Vector() const{
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

void BoolMatrix::BoolVector::Print() const{
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

bool BoolMatrix::BoolVector::operator[](int index) const{
	if (index >= m_lenght)
		return;
	Cell mask = 1;
	mask <<= cellSize - (index % cellSize);
	Cell Temp = Vector[index  / cellSize];
	if (Temp & mask)
		return 1;
	else 
		return 0;
}

BoolMatrix::BoolVector BoolMatrix::BoolVector::operator&(const BoolVector& Other) const{
	if( m_lenght != Other.m_lenght) 
		return ;
	BoolVector Temp(*this);
	for(int i = 0; i < m_cellCount; i++){
		Temp.Vector[i] &= Other.Vector[i];
	}
	return Temp;
}

BoolMatrix::BoolVector& BoolMatrix::BoolVector::operator&=(const BoolVector& Other){
	if( m_lenght != Other.m_lenght) 
		return ;
	for(int i = 0; i < m_cellCount; i++){
		Vector[i] &= Other.Vector[i];
	}
	return *this;
}

BoolMatrix::BoolVector BoolMatrix::BoolVector::operator|(const BoolVector& Other) const{
	if( m_lenght != Other.m_lenght) 
		return ;
	BoolVector Temp(*this);
	for(int i = 0; i < m_cellCount; i++){
		Temp.Vector[i] |= Other.Vector[i];
	}
	return Temp;
}

BoolMatrix::BoolVector& BoolMatrix::BoolVector::operator|=(const BoolVector& Other){
	if( m_lenght != Other.m_lenght) 
		return ;
	for(int i = 0; i < m_cellCount; i++){
		Vector[i] |= Other.Vector[i];
	}
	return *this;
}

BoolMatrix::BoolVector BoolMatrix::BoolVector::operator^(const BoolVector& Other) const{
	if( m_lenght != Other.m_lenght) 
		return ;
	BoolVector Temp(*this);
	for(int i = 0; i < m_cellCount; i++){
		Temp.Vector[i] ^= Other.Vector[i];
	}
	return Temp;
}

BoolMatrix::BoolVector& BoolMatrix::BoolVector::operator^=(const BoolVector& Other){
	if( m_lenght != Other.m_lenght) 
		return ;
	for(int i = 0; i < m_cellCount; i++){
		Vector[i] ^= Other.Vector[i];
	}
	return *this;
}

BoolMatrix::BoolVector BoolMatrix::BoolVector::operator<<(const int shift) const{
	BoolVector Temp(*this);
	int flag = 0;
	if (Temp.m_lenght % cellSize != 0)
	flag = 1;
	int shiftCell = shift / cellSize;
	int shiftTail = shift % cellSize;
	Cell mask = 0;
	if (shift >= Temp.m_lenght){
		for( int i = 0; i < Temp.m_cellCount; i++){
		Temp.Vector[i] = 0;
		} 
		return Temp;
	}
	else{
		for( int i = 0; i < Temp.m_cellCount - shiftCell; i++){
			Temp.Vector[i] = Temp.Vector[i + shiftCell];
		}
		for( int i = Temp.m_cellCount - shiftCell; i < Temp.m_cellCount; i++){
			Temp.Vector[i] = 0;
		}
		if(flag){
			Cell Buffer1 = 0, Buffer2 = 0;
			for (int i = 0; i < Temp.m_lenght % Temp.m_cellCount; i++){
			mask++;
			mask <<= cellSize - 1 - i;
			}
			Temp.Vector[Temp.m_cellCount - 1] &= mask;
			for(int i = Temp.m_cellCount - 1; i <= 0; i-- ){
				Buffer1 = Temp.Vector[i];
				Temp.Vector[i] <<= shiftTail;
				Buffer1 >>= cellSize - shiftTail;
				Temp.Vector[i] |= Buffer2;
				Buffer2 = Buffer1;
			}
			return Temp;
		}
		else
			return Temp;
	}
}

BoolMatrix::BoolVector& BoolMatrix::BoolVector::operator<<=(const int shift){
	int flag = 0;
	if (m_lenght % cellSize != 0)
	flag = 1;
	int shiftCell = shift / cellSize;
	int shiftTail = shift % cellSize;
	Cell mask = 0;
	if (shift >= m_lenght){
		for( int i = 0; i < m_cellCount; i++){
		Vector[i] = 0;
		} 
		return *this;
	}
	else{
		for( int i = 0; i < m_cellCount - shiftCell; i++){
			Vector[i] = Vector[i + shiftCell];
		}
		for( int i = m_cellCount - shiftCell; i < m_cellCount; i++){
			Vector[i] = 0;
		}
		if(flag){
			Cell Buffer1 = 0, Buffer2 = 0;
			for (int i = 0; i < m_lenght % m_cellCount; i++){
			mask++;
			mask <<= cellSize - 1 - i;
			}
			Vector[m_cellCount - 1] &= mask;
			for(int i = m_cellCount - 1; i <= 0; i-- ){
				Buffer1 = Vector[i];
				Vector[i] <<= shiftTail;
				Buffer1 >>= cellSize - shiftTail;
				Vector[i] |= Buffer2;
				Buffer2 = Buffer1;
			}
			return *this;

		}
		else
			return *this;
	}
}

BoolMatrix::BoolVector BoolMatrix::BoolVector::operator>>(const int shift) const{
	BoolVector Temp(*this);
	int flag = 0;
	if (Temp.m_lenght % cellSize != 0)
	flag = 1;
	int shiftCell = shift / cellSize;
	int shiftTail = shift % cellSize;
	Cell mask = 0;
	if (shift >= Temp.m_lenght){
		for( int i = 0; i < Temp.m_cellCount; i++){
		Temp.Vector[i] = 0;
		} 
		return Temp;
	}
	else{
		for( int i = 0; i < Temp.m_cellCount - shiftCell; i++){
			Temp.Vector[i + shiftCell] = Temp.Vector[i];
		}
		for( int i = 0; i < shiftCell; i++){
			Temp.Vector[i] = 0;
		}
		if(flag){
			Cell Buffer1 = 0, Buffer2 = 0;
			for (int i = 0; i < Temp.m_lenght % Temp.m_cellCount; i++){
			mask++;
			mask <<= cellSize - 1 - i;
			}
			Temp.Vector[Temp.m_cellCount - 1] &= mask;
			for(int i = 0; i < Temp.m_cellCount - 1; i++){
				Buffer1 = Temp.Vector[i];
				Temp.Vector[i] >>= shiftTail;
				Buffer1 <<= cellSize - shiftTail;
				Temp.Vector[i] |= Buffer2;
				Buffer2 = Buffer1;
			}
			return Temp;
		}
		else
			return Temp;
	}
} 

BoolMatrix::BoolVector& BoolMatrix::BoolVector::operator>>=(const int shift){
	int flag = 0;
	if (m_lenght % cellSize != 0)
	flag = 1;
	int shiftCell = shift / cellSize;
	int shiftTail = shift % cellSize;
	Cell mask = 0;
	if (shift >= m_lenght){
		for( int i = 0; i < m_cellCount; i++){
		Vector[i] = 0;
		} 
		return *this;
	}
	else{
		for( int i = 0; i < m_cellCount - shiftCell; i++){
			Vector[i + shiftCell] = Vector[i];
		}
		for( int i = 0; i < shiftCell; i++){
			Vector[i] = 0;
		}
		if(flag){
			Cell Buffer1 = 0, Buffer2 = 0;
			for (int i = 0; i < m_lenght % m_cellCount; i++){
			mask++;
			mask <<= cellSize - 1 - i;
			}
			Vector[m_cellCount - 1] &= mask;
			for(int i = 0; i < m_cellCount - 1; i++){
				Buffer1 = Vector[i];
				Vector[i] >>= shiftTail;
				Buffer1 <<= cellSize - shiftTail;
				Vector[i] |= Buffer2;
				Buffer2 = Buffer1;
			}
			return *this;
		}
		else
			return *this;
	}
}

BoolMatrix::BoolVector BoolMatrix::BoolVector::operator~(){
	BoolVector Temp(*this);
	Temp.Inverse_All();
	return Temp;
}

BoolMatrix::BoolVector& BoolMatrix::BoolVector::operator=(const BoolVector& Other){
	delete[] Vector;
	m_lenght = Other.m_lenght;
	m_cellCount = Other.m_cellCount;
	Vector = new Cell[m_cellCount];
	for (int i = 0; i < m_cellCount; i++){
		Vector[i] = Other.Vector[i];
	}
	return *this;
}