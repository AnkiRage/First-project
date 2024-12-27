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


void TopologicalSort(const BoolMatrix& Matrix) {
    int rows = Matrix.Get_Rows(); 
    int cols = Matrix.Get_Cols();
    if (rows != cols) {
        cout << "Matrix must be square\n";
        return;
    }

    vector<int> InDegree(rows, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (Matrix[i][j]) {
                InDegree[j]++;
            }
        }
    }

    vector<int> ZeroInDegree;
    for (int i = 0; i < rows; ++i) {
        if (InDegree[i] == 0) {
            ZeroInDegree.push_back(i);
        }
    }

    vector<int> SortedOrder;
    while (!ZeroInDegree.empty()) {
        int current = ZeroInDegree.front();
        ZeroInDegree.erase(ZeroInDegree.begin());
        SortedOrder.push_back(current);

        for (int j = 0; j < cols; ++j) {
            if (Matrix[current][j]) {
                InDegree[j]--;
                if (InDegree[j] == 0) {
                    ZeroInDegree.push_back(j);
                }
            }
        }
    }

    if (SortedOrder.size() != rows) {
        cout << "Graph have cycle. Sorting impossible.\n";
        return;
    }

    cout << "Topological Sort:\n";
    for (int vertex : SortedOrder) {
        cout << vertex << " ";
    }
   	cout << "\n";
}