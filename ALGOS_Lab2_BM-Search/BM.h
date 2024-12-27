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
using std::string;

int Find_First(string Text, string Substring);
vector<int> Find_All(string Text, string Substring, int start, int end, vector<int>& Found);


