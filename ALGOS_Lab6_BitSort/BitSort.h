#pragma once

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

template <typename Type>
void Swap(Type& A, Type& B)
{
	Type Buff = A;
    A = B;
    B = Buff;
}
// bool Sort(std::vector<int>&arr);
void Out(vector<signed int>& Array);
bool Check_Arr(vector<signed int>& Array);
void Bit_Sort(vector<signed int>& Array, int left, int right );
void SubSort(vector<signed int>& Array, int left, int right, unsigned int mask);