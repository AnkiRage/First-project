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


template <typename Type>
void Swap(Type& A, Type& B)
{
	Type Buff = A;
    A = B;
    B = Buff;
}


class Array
{
public:
	Array(int m = 20); // конструктор по умолчанию размера 20
	Array(int* b, int m); // – конструктор с аргументом, m – число элементов в массиве b
	Array(const Array& x);
	~Array(); // деструктор


	int Get_Size() const;
	void Swap_Arr(Array& B);
	int Find_Value(int value) const;
	void Set_End(int value);
	bool Set_Index(int index, int value);
	void Print() const;
	void Sort();
	bool Del_Index(int index);
	bool Del_Value(int value);
	bool Del_All_Value(int value);
	int Find_Max() const;
	int Find_Min() const;
	void Resize();
	void Resize(int factor);


	int& operator [](int index) const; //?
	Array& operator =(const Array& B); 
	Array& operator+=(int value );
	Array& operator+=(const Array& B);
	Array operator+(int value ) const; 
	Array operator+(const Array& B) const; 
	bool operator==(const Array&B) const;
	bool operator!=(const Array&B) const;

private:
	int* Arr;
	int Capacity, Size;  //Capacity - действительный размер массива ::::  Size - количество элементов в массиве
};


