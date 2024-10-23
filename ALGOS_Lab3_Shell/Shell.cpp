#include "Shell.h"


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


void Sort_Shell(int *Arr, int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && Arr[j] > Arr[j + s]; j -= s) {
                int temp = Arr[j];
                Arr[j] = Arr[j + s];
                Arr[j + s] = temp;
            }
        }
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


