#include "Array.h"
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>

using std::cout;
using std::cin;

int main()
{
	srand(time(0));
	Array A(30);
	for ( int i =0; i < 40; i++){
		int x = rand() % 100 + 1;
		A.Set_End(x);
	}
	A.Print();
	for ( int i =8; i < 17; i++){
		A.Set_End(10);
	}
	A.Print();
	A.Sort();
	// cout << "\n";
	A.Print();
	A.Del_All_Value(10);
	A.Print();
	Array B(A);
	cout << B;
	// B.Print();
	// Array C = B + 1;
	// B.Print();
	// C.Print();

	// cin >> A;
	// cout << A;

	cout << "\nMax = " << A.Find_Max() << " Min = " << A.Find_Min();
	
}