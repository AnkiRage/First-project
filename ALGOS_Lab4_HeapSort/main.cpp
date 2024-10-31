#include "HeapSort.h"

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>

using std::cout;
using std::cin;

int main()
{   
    srand(time(0));
    int n ;
    int *A;
    cout << "Enter n:";
    cin >> n;
    A = new int[n];
    for ( int i = 0; i < n; i++){
        A[i] = rand() % 50 + 1;
    }
    Out(A,n);
    Heap_Sort(A,n);
    Out(A,n);
    Check_Arr(A, n);
    return 0;
}