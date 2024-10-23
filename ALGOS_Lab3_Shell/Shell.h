#pragma once

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>

using std::cout;
using std::cin;


// bool Sort(std::vector<int>&arr);
void Sort_Shell(int *A, int size);
void Out(int *A, int n);
int Check_Arr(int *A, int n);