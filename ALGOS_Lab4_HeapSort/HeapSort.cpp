#include "HeapSort.h"


#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


void Out(int *A, int n){
    cout << "\n\n";
    for (int  i = 0 ; i < n ;i++){
        cout << " " << A[i];
    }
}


void Heap_Build(int *A, int n, int i)
{
    int buf;
    int largest = i;   
    int l = 2*i + 1; 
    int r = 2*i + 2; 

 
    if (l < n && A[l] > A[largest])
        largest = l;

   
    if (r < n && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        buf = A[i];
        A[i] = A[largest];
        A[largest] = buf;
        Heap_Build(A, n, largest);
    }
}


void Heap_Sort(int *A, int n)
{   
    int buf;
    for (int i = n / 2 - 1; i >= 0; i--)
        Heap_Build(A, n, i);


    for (int i=n-1; i>=0; i--)
    {

        buf = A[0];
        A[0] = A[i];
        A[i] = buf;
        Heap_Build(A, i, 0);
    }
}




int  Check_Arr(int *A, int n){
    for (int i = 0; (i + 1) < n && A[i] != A[i+1]; i++){
        cout << "\nNot Sorted";
        return 0;
    }
    cout << "\nSorted";
    return 0;
}


