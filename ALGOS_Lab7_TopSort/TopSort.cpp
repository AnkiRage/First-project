#include "TopSort.h"

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::vector;


bool TopologicalSort(const BoolMatrix& Matrix, vector<int>& SortedOrder ) {
    int rows = Matrix.Get_Rows(); 
    int cols = Matrix.Get_Cols();
    if (rows != cols) {
        return false;
    }

    BoolVector InDegree(rows, false);
    InDegree = Matrix.Mat_Disjunction();

    vector<int> ZeroInDegree;
    for (int i = 0; i < rows; i++) {
        if (!InDegree[i]) {
            ZeroInDegree.push_back(i);
        }
    }

    while (!ZeroInDegree.empty()) {
        int current = ZeroInDegree.back(); 
        ZeroInDegree.pop_back(); 
        SortedOrder.push_back(current);
        for (int j = 0; j < cols; j++) { 
            if (Matrix[current][j]) {
                Matrix.Set_BoolIndex(j, current, false); 
                BoolVector columnDisjunction = Matrix.Mat_Disjunction();
            if (!columnDisjunction[j]) {
                ZeroInDegree.push_back(j);
                }
            }
        }
    }
    if (SortedOrder.size() != rows) {
        return false;
    }

    return true;
}