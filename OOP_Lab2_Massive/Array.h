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


template <typename Type>
void Swap(Type& A, Type& B)
{
	Type Buff = A;
    A = B;
    B = Buff;
}

template <typename ItemType>
class Array
{
public:
	typedef ItemType* iterator; 

	iterator begin();
	iterator end();
	const iterator begin() const;
    const iterator end() const;

	Array(int m = 20); // конструктор по умолчанию размера 20
	Array(ItemType* b, int m); // – конструктор с аргументом, m – число элементов в массиве b
	Array(const Array<ItemType>& x);
	~Array(); // деструктор

	int Get_Size() const;
	void Swap_Arr(Array<ItemType>& B);
	int Find_Value(ItemType value) const;
	void Set_End(ItemType value);
	bool Set_Index(int index, ItemType value);
	void Print() const;
	void Sort();
	bool Del_Index(int index);
	bool Del_Value(ItemType value);
	bool Del_All_Value(ItemType value);
	ItemType Find_Max() const;
	const ItemType& Find_Min() const;
	void Set_BefIt(ItemType value, iterator index);
	void Del_ItRange(iterator start, iterator finish);
	void Del_Iterator(iterator index);

	ItemType& operator [](const int index); 
	const ItemType& operator [](const int index) const; 
	Array<ItemType>& operator =(const Array<ItemType>& B); 
	Array<ItemType>& operator+=(ItemType value );
	Array<ItemType>& operator+=(const Array<ItemType>& B);
	Array<ItemType> operator+(ItemType value ) const; 
	Array<ItemType> operator+(const Array<ItemType>& B) const; 
	bool operator==(const Array<ItemType>&B) const;
	bool operator!=(const Array<ItemType>&B) const;
	

private:
	void Resize();
	void Resize(int factor);

	ItemType* Arr;
	int Capacity, Size;  //Capacity - действительный размер массива ::::  Size - количество элементов в массиве
};

template <typename ItemType>
ostream& operator<<(ostream& os, const Array<ItemType>& Arr){ //////////////////////
	os << '{';
	for (int i = 0 ; i < Arr.Get_Size(); i++){
		os << Arr[i];
		if (i < Arr.Get_Size() - 1)
			os << ", ";
	}
	os << '}';
	return os;
}

template <typename ItemType>
istream& operator>>(istream& is, Array<ItemType>& Arr){ //////////////////////
	for (int i = 0 ; i < Arr.size(); i++){
		is >> Arr[i];
	}
	return is;
}

template <typename ItemType>
Array<ItemType>::Array(int m) {
	Arr = new ItemType[m];
	Capacity = m;
    Size = 0;
}

template <typename ItemType>
Array<ItemType>::Array (const Array& B) {
	Capacity = B.Capacity;
	Size = B.Size;
	Arr = new ItemType[Capacity];
	for (int i = 0; i < Size; i++) {
		Arr[i] = B.Arr[i];
	}
}

template <typename ItemType>
Array<ItemType>::Array(ItemType* b, int m) {
	Arr = b;
	Size = m;
	Capacity = m + m / 3;
}

template <typename ItemType>
Array<ItemType>::~Array() {
	delete[] Arr;
}

template <typename ItemType> 
typename Array<ItemType>::iterator Array<ItemType>::begin(){
    return Arr;
}

template <typename ItemType> 
typename Array<ItemType>::iterator Array<ItemType>::end(){
    return Arr + Size;
}

template <typename ItemType>
const typename Array<ItemType>::iterator Array<ItemType>::begin() const{
    return Arr;
}

template <typename ItemType>
const typename Array<ItemType>::iterator Array<ItemType>::end() const{
    return Arr + Size;
}

template <typename ItemType>
int Array<ItemType>::Get_Size() const{
    return Size;
}

template <typename ItemType>
void Array<ItemType>::Resize(){
	ItemType *Arr2;
	Arr2 = new ItemType[Size + Size / 3];
	Capacity = Size + Size / 3;
	for (int i = 0 ; i < Size; i++){
		Arr2[i] = Arr[i];
	}
	
	delete[] Arr;
	Arr = Arr2;
}

template <typename ItemType>
void Array<ItemType>::Resize( int factor){
	ItemType *Arr2;
	Arr2 = new ItemType [Capacity + factor + (factor + Capacity) / 3];
	for (int i = 0 ; i < Size; i++){
		Arr2[i] = Arr[i];
	}
	Capacity = Capacity + factor + (factor + Capacity) / 3 ;
	delete[] Arr;
	Arr = Arr2;
}

template <typename ItemType>
void Array<ItemType>::Swap_Arr(Array<ItemType>& B){
    Swap(Arr, B.Arr);
    Swap(Size, B.Size );
    Swap(Capacity, B.Capacity );
}

template <typename ItemType>
int Array<ItemType>::Find_Value(ItemType value) const{
    for (int i = 0; i < Size; i++){
        if ( Arr[i] == value) 
            return i;
    }
    return -1;
}

template <typename ItemType>
void Array<ItemType>::Set_End(ItemType value){
    if ( Size == Capacity){
        Resize();
    }
	*end() = value;
	Size++;
}

template <typename ItemType>
bool Array<ItemType>::Set_Index(int index, ItemType value){
	if (index >= Size){
		return false;
	}
	if (Size == Capacity){
		Resize();
	}
	Size++;
	for (int i = index - 1; i < Size - 1; i++){
		Array[i + 1] = Array[i];
	}
	Array[index - 1] = value;
	return true;
}

template <typename ItemType>
void Array<ItemType>::Print() const{
	for(iterator i = begin() ; i != end(); i++){
		cout << *i << " ";
	}
	cout << "\n";
}

template <typename ItemType>
void Array<ItemType>::Sort(){
	for (int s = Size / 2; s > 0; s /= 2) {
        for (int i = s; i < Size; ++i) {
            for (int j = i - s; j >= 0 && Arr[j] > Arr[j + s]; j -= s) {
				int temp = Arr[j];
                Arr[j] = Arr[j + s];
                Arr[j + s] = temp;
            }
        }
    }
}

template <typename ItemType>
bool Array<ItemType>::Del_Index(int index){
	if (index >= Size ){
		return false;
	}

	for( int i = index; i < Size -1; i++){
		Arr[i] = Arr[i + 1];
	}
	Size --;

	if (Capacity > 2 * Size)
		Resize();

	return true;
}

template <typename ItemType>
bool Array<ItemType>::Del_Value(ItemType value){
	for (int i = 0; i < Size; i++){
        if ( Arr[i] == value) {
        	for(int g = i ; g < Size - 1; g++){
				Arr[g] = Arr[g+1];
			}
			Size --;
			if (Capacity > 2 * Size)
				Resize();
			return true;
		}
    }
    return false;
}

template <typename ItemType>
bool Array<ItemType>::Del_All_Value(ItemType value){
	bool found = false;
	for (int i = 0; i < Size; i++){
        if (Arr[i] == value) {
			found = true;
        	for(int g = i ; g < Size - 1; g++){
				Arr[g] = Arr[g+1];
			}
			i--;
			Size--;
		}
    }
	if (Capacity > 2 * Size)
		Resize();
	return found;
}

template <typename ItemType>
ItemType Array<ItemType>::Find_Max() const{
	if (Size == 0) return;
	iterator it = begin();
	iterator max = it;
	it++;
	while (it != end()) {
		if (*it > *max)
		{
			max = it;
		}
		it++;
	}
	return *max;
}
template <typename ItemType>
const ItemType& Array<ItemType>::Find_Min() const{
	if (Size == 0) return;
	iterator it = begin();
	iterator min = it;
	it++;
	while (it != end()) {
		if (*it < *min)
		{
			min = it;
		}
		it++;
	}
	return *min;
}

template <typename ItemType>
ItemType& Array<ItemType>::operator [](const int index){
	return Arr[index];
}

template <typename ItemType>
const ItemType& Array<ItemType>::operator [](const int index) const{
	return Arr[index];
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator=(const Array<ItemType>& B){
	// arr = arr ?
	Capacity = B.Capacity;
	Size = B.Size;
	ItemType *Arr2 = new ItemType[Capacity];
	for (int i = 0; i < Size; i++){
		Arr2[i] = B.Arr[i];
	}
	delete Arr;
	Arr = Arr2;
	return *this;
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator+=(ItemType value ){
	Set_End(value);
	return *this;
}

template <typename ItemType>
Array<ItemType>& Array<ItemType>::operator+=(const Array<ItemType>& B){
	if (Capacity < Size + B.Size){
		Resize(B.Size);
	}
	for(int i = 0; i < B.Size; i++){
		Arr[Size++] = B[i];
	}
	return *this;
}

template <typename ItemType>
Array<ItemType> Array<ItemType>::operator+(ItemType value ) const{
	Array<ItemType> Result(*this);
	Result += value;
	return Result;
}  

template <typename ItemType>
Array<ItemType> Array<ItemType>::operator+(const Array<ItemType>& B) const{
	Array<ItemType> Result(*this);
	Result += B;
	return Result;
}

template <typename ItemType>
bool Array<ItemType>::operator==(const Array<ItemType>&B) const{
	if( Size != B.Size){
		return false;
	}
	for(int i = 0; i < Size; i++){
		if (Arr[i] != B.Arr[i])
			return false;
	}
	return true;
}

template <typename ItemType>
bool Array<ItemType>::operator!=(const Array<ItemType>&B) const{
	return !operator==(B);
}

template <typename ItemType>
void Array<ItemType>::Set_BefIt(ItemType value, iterator index){
	if (index < begin() || index => end()) 
		return;
	if (end() == &Arr[Capacity]) 
		Resize();
	*(index - 1) = value;
}

template <typename ItemType>
void Array<ItemType>::Del_ItRange(iterator start, iterator finish){
	int diff = finish - start;
	for(iterator i = start; i != end() - diff; i++){
		*(i) = *(i + diff);
	}
	Size -= diff;
	if (Capacity > 2 * Size){
		Resize();
	}
}

template <typename ItemType>
void Array<ItemType>::Del_Iterator(iterator index){
	Del_Index(index - begin());
}
