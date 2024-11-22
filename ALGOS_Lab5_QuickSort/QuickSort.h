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


// bool Sort(std::vector<int>&arr);
void Swap(int& A, int& B);
void Out(vector<int>& Array);
bool Check_Arr(vector<int>& Array);
void Quick_Sort(vector<int>& Array, int left, int right );