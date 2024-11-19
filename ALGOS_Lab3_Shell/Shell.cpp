#include "Shell.h"


#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>

using std::cout;


void Out(vector<int>& A){
    cout << "\n\n";
    for (int  i = 0 ; i < A.size() ;i++){
        cout << " " << A[i];
    }
}



void Sort_Shell_Usual(vector<int>& Arr) {
    for (int s = Arr.size() / 2; s > 0; s /= 2) {
        for (int i = s; i < Arr.size(); ++i) {
            for (int j = i - s; j >= 0 && Arr[j] > Arr[j + s]; j -= s) {
                int temp = Arr[j];
                Arr[j] = Arr[j + s];
                Arr[j + s] = temp;
            }
        }
    }
}


void Sort_Shell_Sedjwick(vector<int>& Arr) {
    int s = 5;
    for (; s > 0; s /= 2) {

        for (int i = s; i < Arr.size(); ++i) {
            for (int j = i - s; j >= 0 && Arr[j] > Arr[j + s]; j -= s) {
                int temp = Arr[j];
                Arr[j] = Arr[j + s];
                Arr[j + s] = temp;
            }
        }
    }
}


bool Check_Arr(vector<int>& A){
    for (int i = 0; (i + 1) < A.size() ; i++)
        if (A[i] > A[i+1])
            return false;
    return true;
}