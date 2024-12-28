#pragma once

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include <vector>

#include "../OOP_Lab3_BoolVector/BoolVector.h"
#include "../OOP_Lab4_BoolMatrix/BoolMatrix.h"


using std::cout;
using std::cin;
using std::vector;


bool TopologicalSort(const BoolMatrix& Matrix, vector<int>& SortedOrder );
