#include "HeapSort.h"


#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using std::vector;
using std::cout;
using std::cin;


void Out(vector<int>& Array){
    cout << "\n\n";
    for (int  i = 0 ; i < Array.size() ;i++){
        cout << " " << Array[i];
    }
}


void Heap_Build(vector<int>& Array,int n, int i){
    int buf;
    int largest = i;   
    int l = 2*i + 1; 
    int r = 2*i + 2; 

 
    if (l < n && Array[l] > Array[largest])
        largest = l;

   
    if (r < n && Array[r] > Array[largest])
        largest = r;

    if (largest != i)
    {
        buf = Array[i];
        Array[i] = Array[largest];
        Array[largest] = buf;
        Heap_Build(Array, n, largest);
    }
}


void Heap_Sort(vector<int>& Array)
{   
    int buf;
    for (int i = Array.size() / 2 - 1; i >= 0; i--)
        Heap_Build(Array, Array.size(), i);


    for (int i=Array.size()-1; i>=0; i--)
    {

        buf = Array[0];
        Array[0] = Array[i];
        Array[i] = buf;
        Heap_Build(Array, i , 0);
    }
}




bool  Check_Arr(vector<int>& Array){
        for (int i = 0; (i + 1) < Array.size() ; i++)
       if (Array[i] > Array[i+1])  return false;
    

       return true;
}

