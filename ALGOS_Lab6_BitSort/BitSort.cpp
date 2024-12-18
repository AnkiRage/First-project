#include "BitSort.h"


#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using std::vector;
using std::cout;
using std::cin;


void Out(vector<signed int>& Array){
    cout << "\n\n";
    for (int  i = 0 ; i < Array.size() ;i++){
        cout << " " << Array[i];
    }
}

void SubSort(vector<signed int>& Array, int left, int right, unsigned int mask){
    if (left >= right || mask == 0)
        return;

    mask >>= 1;
    
    int start = left;
    int end = right;

     while (left <= right) {
        while (left <= end && ((Array[left] & mask) == 0))
            left++;
        while (right >= start && ((Array[right] & mask) != 0))
            right--;
        if (left <= right) {
            Swap(Array[left], Array[right]);
            left++;
            right--;
        }
    }
    SubSort(Array, start, right, mask);
    SubSort(Array, left, end, mask);
}

void Bit_Sort(vector<signed int>& Array, int left, int right)
{   
    signed int mask = 1 << 31;

    int start = left;
    int end = right;

    while (left <= right) {
        while (left <= end && ((Array[left] & mask) != 0))
            left++;
        while (right >= start && ((Array[right] & mask) == 0))
            right--;
        if (left <= right) {
            Swap(Array[left], Array[right]);
            left++;
            right--;
        }
    }
    SubSort(Array, start, right, mask);
    SubSort(Array, left, end, mask);
}




bool Check_Arr(vector<signed int>& Array){
    for (int i = 0; (i + 1) < Array.size() ; i++)
        if (Array[i] > Array[i+1])
            return false;
    return true;
}

