#include "TopSort.h"
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>

using UI = unsigned int;
#define UC unsigned char


using std::cout;
using std::cin;

int main()
{
	BoolMatrix Matrix(4, 4, false);
	cout << "cols and rows = " << Matrix.Get_Cols() << " " << Matrix.Get_Rows();
	Matrix.Set_BoolIndex(1, 0, true);
	Matrix.Set_BoolIndex(2, 0, true);
	Matrix.Set_BoolIndex(3, 1, true);
	Matrix.Set_BoolIndex(3, 2, true);
	cout << Matrix;

	TopologicalSort(Matrix);
}