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
	m_cellCount = lenght / cellSize;
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
	m_cellCount = lenght / cellSize;
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
	m_cellCount = lenght / cellSize;
	if (lenght % cellSize != 0)
		m_cellCount++;
	Vector = new Cell[m_cellCount];
	Cell mask = 0;
	for (int i = 0; i < m_cellCount; i++){
		for (int g = 0, mask = 0; g < cellSize; g++){
			if (CharVector[i * cellSize + g ] == '1')
				mask++;
			mask <<= 1;
		}
		Vector[i] = mask;
	}
}

BoolVector::~BoolVector(){
	delete[] Vector;
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