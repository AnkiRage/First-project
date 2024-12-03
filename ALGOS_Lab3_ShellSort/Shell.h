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

enum ShellSortType
{
    Shell,
    Hibbard,
    Sedgewick
};

void Sort_Shell(vector<int>& Arr, ShellSortType type);
void Sort_Shell_Usual(vector<int>& Arr);
void Sort_Shell_Sedjwick(vector<int>& Arr);
void Sort_Shell_Hibbard(vector<int>& Arr);
void Out(vector<int>& A);
bool Check_Arr(vector<int>& A);