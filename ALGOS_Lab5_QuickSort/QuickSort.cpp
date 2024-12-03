#include "QuickSort.h"


#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using std::vector;
using std::cout;
using std::cin;


void Swap(int& A, int& B){
    int buff = A;
    A = B;
    B = buff;
}

void Out(vector<int>& Array){
    cout << "\n\n";
    for (int  i = 0 ; i < Array.size() ;i++){
        cout << " " << Array[i];
    }
}




void Quick_Sort(vector<int>& Array, int left, int right)
{   
    if (left >= right)
        return;

    int Pivot_Index = left + rand() % (right - left + 1);
    Swap(Array[Pivot_Index], Array[right]);
    int pivot = Array[right];

    int start = left;
    int end = right;
    right--;

    while (left <= right) {
        while (left <= end && Array[left] < pivot)
            left++;
        while (right >= start && Array[right] > pivot)
            right--;
        if (left <= right) {
            Swap(Array[left], Array[right]);
            left++;
            right--;
        }
    }
    Swap(Array[left], Array[end]);
    left++;

    Quick_Sort(Array, start, right);
    Quick_Sort(Array, left, end);
}




bool Check_Arr(vector<int>& Array){
    for (int i = 0; (i + 1) < Array.size() ; i++)
        if (Array[i] > Array[i+1])
            return false;
    return true;
}

