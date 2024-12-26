#include "TSP.h"


#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>

#include <algorithm>
#include <random>

using std::cout;
using std::numeric_limits;


void Gen_Matrix(vector<vector<int>>& matrix, int n, int minCost, int maxCost) {
    srand(time(0));
    matrix.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matrix[i][j] = rand() * rand() % (maxCost - minCost + 1) + minCost  ;
            }
        }
    }
}


void Exact_TSP(const vector<vector<int>>& matrix, int startCity, int& minCost, vector<int>& bestPath) {
    int n = matrix.size();
    vector<int> cities;
    for (int i = 0; i < n; ++i) {
        if (i != startCity) {
            cities.push_back(i);
        }
    }

    minCost = numeric_limits<int>::max();
    bestPath.clear();

    while (std::next_permutation(cities.begin(), cities.end())){
        int currentCost = 0;
        int currentCity = startCity;

        for (int city : cities) {
            currentCost += matrix[currentCity][city];
            currentCity = city;
        }
        currentCost += matrix[currentCity][startCity];

        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = cities;
        }
    } 

    bestPath.insert(bestPath.begin(), startCity);
    bestPath.push_back(startCity);
}

void Greedy_TSP(const vector<vector<int>>& matrix, int startCity, int& cost, vector<int>& path) {
    int n = matrix.size();
    vector<bool> visited(n, false);

    path.clear();
    cost = 0;

    int currentCity = startCity;
    path.push_back(currentCity);
    visited[currentCity] = true;

    for (int i = 1; i < n; ++i) {
        int nextCity = -1;
        int minCost = numeric_limits<int>::max();

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && matrix[currentCity][j] < minCost) {
                minCost = matrix[currentCity][j];
                nextCity = j;
            }
        }

        if (nextCity != -1) {
            visited[nextCity] = true;
            path.push_back(nextCity);
            cost += minCost;
            currentCity = nextCity;
        }
    }

    cost += matrix[currentCity][startCity];
    path.push_back(startCity);
}