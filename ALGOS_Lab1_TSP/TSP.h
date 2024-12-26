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

void Gen_Matrix(vector<vector<int>>& matrix, int n, int minCost, int maxCost);
void Exact_TSP(const vector<vector<int>>& matrix, int startCity, int& minCost, vector<int>& bestPath);
void Greedy_TSP(const vector<vector<int>>& matrix, int startCity, int& cost, vector<int>& path);