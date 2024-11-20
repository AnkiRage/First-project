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
    int s = 0;
    for (int count; 3*count < Arr.size(); count++) {
        if (count%2 == 1)
            s = 8 * 2 ^ count - 6 * 2 ^ (count + 1) / 2;
        else  s = 9 * 2 ^ count - 9 * 2 ^ count / 2;

        for (int i = s; i < Arr.size(); ++i) {
            for (int j = i - s; j >= 0 && Arr[j] > Arr[j + s]; j -= s) {
                int temp = Arr[j];
                Arr[j] = Arr[j + s];
                Arr[j + s] = temp;
            }
        }
    }
}

void Sort_Shell_Hibbar(vector<int>& Arr){
    int s;
    for (int count = 0; 2 ^ count - 1 <= Arr.size(); count++) {
        s = 2 ^ count - 1;
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