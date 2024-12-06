#include "Array.h"

// #include <iostream>
// #include <cmath>
// #include <time.h>
// #include <stdlib.h>
// #include <string.h>
// #include <windows.h>
// #include <stdio.h>
// #include <iomanip>

// using std::cout;
// using std::cin;
// using std::ostream;
// using std::istream;

// ostream& operator<<(ostream& os, const Array& Arr){ //////////////////////
// 	os << '{';
// 	for (int i = 0 ; i < Arr.Get_Size(); i++){
// 		os << Arr[i];
// 		if (i < Arr.Get_Size() - 1)
// 			os << ", ";
// 	}
// 	os << '}';
// 	return os;
// }

// istream& operator>>(istream& is, Array& Arr){ //////////////////////
// 	for (int  i = 0 ; i < Arr.Get_Size(); i++){
// 		is >> Arr[i];
// 	}
// 	return is;
// }

// Array::Array(int m) {
// 	Arr = new int[m];
// 	Capacity = m;
//     Size = 0;
// }

// Array::Array (const Array& B) {
// 	Capacity = B.Capacity;
// 	Size = B.Size;
// 	Arr = new int[Capacity];
// 	for (int i = 0; i < Size; i++) {
// 		Arr[i] = B.Arr[i];
// 	}
// }

// Array::Array(int* b, int m) {
// 	Arr = b;
// 	Size = m;
// 	Capacity = m + m / 3;
// }

// Array::~Array() {
// 	delete Arr;
// }

// int Array::Get_Size() const{
//     return Size;
// }

// void Array::Resize(){
// 	int *Arr2;
// 	Arr2 = new int [Capacity + Capacity / 3];
// 	for (int i = 0 ; i < Size; i++){
// 		Arr2[i] = Arr[i];
// 	}
// 	Capacity = Capacity + Capacity / 3 ;
// 	delete Arr;
// 	Arr = Arr2;
// }

// void Array::Resize(int factor){
// 	int *Arr2;
// 	Arr2 = new int [Capacity + factor + (factor + Capacity) / 3];
// 	for (int i = 0 ; i < Size; i++){
// 		Arr2[i] = Arr[i];
// 	}
// 	Capacity = Capacity + factor + (factor + Capacity) / 3 ;
// 	delete Arr;
// 	Arr = Arr2;
// }

// void Array::Swap_Arr(Array& B){
//     Swap(Arr, B.Arr);
//     Swap(Size, B.Size );
//     Swap(Capacity, B.Capacity );
// }

// int Array::Find_Value(int value) const{
//     for (int i = 0; i < Size; i++){
//         if ( Arr[i] == value) 
//             return i;
//     }
//     return -1;
// }

// void Array::Set_End(int value){
//     if ( Size == Capacity){
//         Resize();
//     }
// 	Arr[Size] = value;
// 	Size++;
// }

// bool Array::Set_Index(int index, int value){
// 	if (index >= Size){
// 		return false;
// 	}
// 	Arr[index] == value;
// 	return true;
// }

// void Array::Print() const{
// 	for( int i = 0 ; i < Size; i++){
// 		cout << Arr[i] << " ";
// 	}
// 	cout << "\n";
// }

// void Array::Sort(){
// 	for (int s = Size / 2; s > 0; s /= 2) {
//         for (int i = s; i < Size; ++i) {
//             for (int j = i - s; j >= 0 && Arr[j] > Arr[j + s]; j -= s) {
//                 int temp = Arr[j];
//                 Arr[j] = Arr[j + s];
//                 Arr[j + s] = temp;
//             }
//         }
//     }
// }

// bool Array::Del_Index(int index){
// 	if (index >= Size ){
// 		return false;
// 	}
// 	for( int i = index; i < Size -1; i++){
// 		Arr[i] = Arr[i + 1];
// 	}
// 	Size --;
// 	return true;
// }

// bool Array::Del_Value(int value){
// 	for (int i = 0; i < Size; i++){
//         if ( Arr[i] == value) {
//         	for(int g = i ; g < Size - 1; g++){
// 				Arr[g] = Arr[g+1];
// 			}
// 		Size --;
// 		return true;
// 		}

//     }
//     return false;
// }

// bool Array::Del_All_Value(int value){
// 	int flag = 0;
// 	for (int i = 0; i < Size; i++){
//         if ( Arr[i] == value) {
// 			flag = 1;
//         	for(int g = i ; g < Size - 1; g++){
// 				Arr[g] = Arr[g+1];
// 			}
// 		i--;
// 		Size --;
// 		}

//     }
// 	if (flag)
//     	return true;
// 	else return false;
// }

// int Array::Find_Max() const{
// 	int max = Arr[0];
// 	for( int i = 1 ; i < Size; i++){
// 		if(max < Arr[i])
// 			max = Arr[i];
// 	}
// 	return max;
// }

// int Array::Find_Min() const{
// 	int min = Arr[0];
// 	for( int i = 1 ; i < Size; i++){
// 		if(min > Arr[i])
// 			min = Arr[i];
// 	}
// 	return min;
// }

// int& Array::operator [](const int index){
// 	return Arr[index];
// }

// const int& Array::operator [](const int index) const{
// 	return Arr[index];
// }


// Array& Array::operator=(const Array& B){
// 	Capacity = B.Capacity;
// 	Size = B.Size;
// 	int *Arr2 = new int[Capacity];
// 	for (int i = 0; i < Size; i++){
// 		Arr2[i] = B.Arr[i];
// 	}
// 	delete Arr;
// 	Arr = Arr2;
// 	return *this;
// }

// Array& Array::operator+=(int value ){
// 	Set_End(value);
// 	return *this;
// }

// Array& Array::operator+=(const Array& B){
// 	if (Capacity < Size + B.Size){
// 		Resize(B.Size);
// 	}
// 	for(int i = 0; i < B.Size; i++){
// 		Arr[Size++] = Arr[i];
// 	}
// 	return *this;
// }

// Array Array::operator+(int value ) const{
// 	Array Result(*this);
// 	Result.Set_End(value);
// 	return Result;
// }  

// Array Array::operator+(const Array& B) const{
// 	Array Result(*this);
// 	if (Result.Capacity < Result.Size + B.Size){
// 		Result.Resize(B.Size);
// 	}
// 	for(int i = 0; i < B.Size; i++){
// 		Arr[Result.Size++] = Arr[i];
// 	}
// 	return Result;
// }

// bool Array::operator==(const Array&B) const{
// 	if( Size != B.Size){
// 		return false;
// 	}
// 	for(int i = 0; i < Size; i++){
// 		if (Arr[i] != B.Arr[i])
// 			return false;
// 	}
// 	return true;
// }

// bool Array::operator!=(const Array&B) const{
// 	if( Size != B.Size){
// 		return true;
// 	}
// 	for(int i = 0; i < Size; i++){
// 		if (Arr[i] == B.Arr[i])
// 			return false;
// 	}
// 	return true;
// }

