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
	Array<int> A(30);
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
	Array<int> B(A);
	Array<int> C;
	cout << B;
	B[0] = 17;
	cout << "\n" << B << "\nArr[2] = " << B[2];
	// cin >> B[3];
	// cout << B;
	cout << "\niterator[9] = " << *(B.begin() + 9) << "   end = " << *(B.end() - 1); 
	cout << "Find value: " << B.Find_Value(17);
	// B.Print();
	// Array<int> C = B + 1;
	// B.Print();
	// C.Print();

	// cin >> A;
	// cout << A;

	cout << "\nMax = " << A.Find_Max() << " Min = " << A.Find_Min();
	
}