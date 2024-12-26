#include "TSP.h"

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <chrono>

using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
int main()
{   
    int minCost = 1;
    int maxCost = 10;
    vector<int> ExactPath;
    vector<int> GreedyPath;
    int ExactCost;
    int GreedyCost;

for(int f = 0; f < 4; f++){
    cout << "\n\n" << f + 1 << " ITERATION:\n\n";
    minCost *= 10;
    maxCost *= 10;
    cout << "minCost = " << minCost << "\n" << "maxCost = " << maxCost << "\n";
    for (int n = 4; n <= 10; n += 2) {
        cout << "\nMatrix size: " << n << "x" << n << "\n";

        vector<vector<int>> matrix;
        Gen_Matrix(matrix, n, minCost, maxCost);

        cout << "Cost matrix:" << "\n";
        for (int i = 0; i < n; i++) {
            for (int g = 0; g < n ; g++) {
                if(i == g){
                    cout << "-- ";
                    continue;
                }
                cout << matrix[i][g] << " ";
            }
            cout << "\n";
        }

        int startCity = 0;

        auto Start = high_resolution_clock::now();
        Exact_TSP(matrix, startCity, ExactCost, ExactPath);
        auto End = high_resolution_clock::now();
        duration<double> ExactDuration = End - Start;
        Start = high_resolution_clock::now();
        Greedy_TSP(matrix, startCity, GreedyCost, GreedyPath);
        End = high_resolution_clock::now();
        duration<double> GreedyDuration = End - Start;

        cout << "\nExact solution:\n";
        cout << "Cost: " << ExactCost << "\n";
        cout << "Path: ";
        for (int city : ExactPath) {
            cout << city << " ";
        }
        cout << "\nTime: " << ExactDuration.count() << " seconds\n";

        cout << "\nGreedy solution:\n";
        cout << "Cost: " << GreedyCost << "\n";
        cout << "Path: ";
        for (int city : GreedyPath) {
            cout << city << " ";
        }
        cout << "\nTime: " << GreedyDuration.count() << " seconds\n";

        double quality = 100.0 * (double)(GreedyCost - ExactCost) / (double)ExactCost;
        cout << "\nGreedy solution quality: " << 100.0 - quality << "%\n";
    }
}

    return 0;
}