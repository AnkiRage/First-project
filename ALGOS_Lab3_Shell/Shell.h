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


// bool Sort(std::vector<int>&arr);
void Sort_Shell_Usual(vector<int>& Arr);
void Sort_Shell_Sedjwick(vector<int>& Arr);
void Sort_Shell_(vector<int>& Arr);
void Out(vector<int>& A);
bool Check_Arr(vector<int>& A);