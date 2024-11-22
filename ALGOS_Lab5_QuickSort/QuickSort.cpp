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
    int buff;
    buff = A;
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
    if (left >= right ) return;
    int start = left;
    int end = right;
    //cout << " start = " << start << " end = " << end ;
    int pivot = Array[right];
    // cout << " \npivot " << pivot; 
    right --;

    while (left <= right)
    {   
        while ((Array[left] < pivot) && left <= end)
            left++;
        while ((Array[right] > pivot) && right >= start)
            right--;
        if (left <= right){
            Swap(Array[left], Array[right]);
            left++;
            right--;
        }
    }
    Swap(pivot, Array[left]);
    Quick_Sort(Array, start, left -1);
    Quick_Sort(Array, left + 1, end);
}




bool  Check_Arr(vector<int>& Array){
        for (int i = 0; (i + 1) < Array.size() ; i++)
       if (Array[i] > Array[i+1])  return false;
    

       return true;
}

