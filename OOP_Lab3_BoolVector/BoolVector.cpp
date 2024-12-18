#include "BoolVector.h"

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include <assert.h>

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
		mask = ~mask;
	for (int i = 0; i < m_cellCount; i++){
		Vector[i] = mask;
	}
}

BoolVector::BoolVector(char* CharVector, int lenght){
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

bool BoolVector::operator[](int index) const{
	if (index >= m_lenght)
		return false;
	Cell mask = 1;
	mask <<= cellSize - (index % cellSize) - 1;
	Cell Temp = Vector[index / cellSize];
	if (Temp & mask)
		return 1;
	else 
		return 0;
}

BoolVector::Rank BoolVector::operator[](int index)
{
	assert(index >= 0 && index < m_lenght);
    return Rank(&Vector[index / cellSize], _mask(index));
}

BoolVector BoolVector::operator&(const BoolVector& Other) const{
	if( m_lenght != Other.m_lenght) 
		return *this;
	BoolVector Temp(*this);
	for(int i = 0; i < m_cellCount; i++){
		Temp.Vector[i] &= Other.Vector[i];
	}
	return Temp;
}

BoolVector& BoolVector::operator&=(const BoolVector& Other){
	if( m_lenght != Other.m_lenght) 
		return *this;
	for(int i = 0; i < m_cellCount; i++){
		Vector[i] &= Other.Vector[i];
	}
	return *this;
}

BoolVector BoolVector::operator|(const BoolVector& Other) const{
	if( m_lenght != Other.m_lenght) 
		return *this;
	BoolVector Temp(*this);
	for(int i = 0; i < m_cellCount; i++){
		Temp.Vector[i] |= Other.Vector[i];
	}
	return Temp;
}

BoolVector& BoolVector::operator|=(const BoolVector& Other){
	if( m_lenght != Other.m_lenght) 
		return *this;
	for(int i = 0; i < m_cellCount; i++){
		Vector[i] |= Other.Vector[i];
	}
	return *this;
}

BoolVector BoolVector::operator^(const BoolVector& Other) const{
	if( m_lenght != Other.m_lenght) 
		return *this;
	BoolVector Temp(*this);
	for(int i = 0; i < m_cellCount; i++){
		Temp.Vector[i] ^= Other.Vector[i];
	}
	return Temp;
}

BoolVector& BoolVector::operator^=(const BoolVector& Other){
	if( m_lenght != Other.m_lenght) 
		return *this;
	for(int i = 0; i < m_cellCount; i++){
		Vector[i] ^= Other.Vector[i];
	}
	return *this;
}

BoolVector BoolVector::operator<<(const int shift) const{
	BoolVector Temp(*this);
	Temp <<= shift;
	return Temp;
}

BoolVector& BoolVector::operator<<=(const int shift){
	if (shift >= m_lenght){
		Set_All(0);
		return *this;
	}
	int shiftTail = shift % cellSize;
	int shiftCell = shift / cellSize;

	if (shiftCell)
	{
		for( int i = 0; i < m_cellCount - shiftCell; i++){
			Vector[i] = Vector[i + shiftCell];
		}
		for( int i = m_cellCount - shiftCell; i < m_cellCount; i++){
			Vector[i] = 0;
		}
	}
	
	if(shiftTail){
		Cell Buffer1 = 0, Buffer2 = 0;
		for(int i = m_cellCount - 1; i >= 0; i--){
			Buffer1 = Vector[i];
			Vector[i] <<= shiftTail;
			Buffer1 >>= cellSize - shiftTail;
			Vector[i] |= Buffer2;
			Buffer2 = Buffer1;
		}
	}

	if (m_lenght % cellSize != 0) {
        Vector[m_cellCount - 1] &= ~((1 << (cellSize - m_lenght % cellSize)) - 1);
    }

	return *this;
}

BoolVector BoolVector::operator>>(const int shift) const{
	BoolVector Temp(*this);
	Temp >>= shift;
	return Temp;
} 

BoolVector& BoolVector::operator>>=(const int shift){
	if (shift >= m_lenght){
		Set_All(0);
		return *this;
	}

	int shiftTail = shift % cellSize;
	int shiftCell = shift / cellSize;
	if (shiftCell){
		for (int i = m_cellCount - 1; i >= shiftCell; --i) {
            Vector[i] = Vector[i - shiftCell];
        }
        for (int i = 0; i < shiftCell; ++i) {
            Vector[i] = 0;
		}
	}
	if(shiftTail){
		Cell Buffer1 = 0, Buffer2 = 0;
		for(int i = 0; i < m_cellCount ; i++){
			Buffer1 = Vector[i];
			Vector[i] >>= shiftTail;
			Buffer1 <<= cellSize - shiftTail;
			Vector[i] |= Buffer2;
			Buffer2 = Buffer1;
		}
	}

	if (m_lenght % cellSize != 0) {
        Vector[m_cellCount - 1] &= ~((1 << (cellSize - m_lenght % cellSize)) - 1);
    }

	return *this;
}

BoolVector BoolVector::operator~(){
	BoolVector Temp(*this);
	Temp.Inverse_All();
	return Temp;
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
ostream& operator<<(ostream& os, const BoolVector& Vector){
	os << '{';
	for (int i = 0; i < Vector.Get_Lenght(); ++i)
	{
		os << Vector[i];
	}
	os << '}';
	return os;
}
istream& operator>>(istream& is, BoolVector& Vector){
	char bit;
	for (int i = 0; i < Vector.Get_Lenght(); ++i)
	{
		is >> bit;
		Vector.Set_Index(i, bit == '1');
	}
	return is;
	
}

int BoolVector::_excessRankCount() const
{
	return (m_cellCount * cellSize - m_lenght);
}

BoolVector::Cell BoolVector::_mask(int index)
{
    Cell mask = 1;
	mask <<= cellSize - 1 - (index % cellSize);
	return mask;
}

BoolVector::Rank::Rank(Cell* cell, Cell mask)
    : m_cell(cell)
    , m_mask(mask)
{
    assert(m_cell != nullptr);
    assert(m_mask > 0);
}

BoolVector::Rank& BoolVector::Rank::operator=(const Rank& other)
{
    return operator=(static_cast<bool>(other));
}

BoolVector::Rank& BoolVector::Rank::operator=(bool value)
{
    if (value){
        *m_cell |= m_mask;
    }
    else{
        *m_cell &= ~m_mask;
    }
    return *this;
}

BoolVector::Rank::operator bool() const
{
	return (*m_cell & m_mask) != 0;
}