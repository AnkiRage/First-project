#include "QuickSort.h"

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::string;
int main()
{   
    srand(time(0));
    clock_t time , av_time ;
    double time_seconds;
    int size = 10000, range = 10, m_range, m_size;
    FILE* f;
    vector<int> Array(size);

    

    for(int i = 1, m_size = size; i <=3; m_size*=10, i++){
        Array.resize(m_size);

        for (int i =1, m_range = range, av_time = 0; i <=3 ; m_range*=100, i++){
            string filename = "Input_data_size_" + std::to_string(m_size) + "_range_" + std::to_string(m_range) + ".txt";
            f = fopen( filename.c_str(), "r");
            for(int i = 0 ; i < m_size; i++){
                    fscanf(f, " %d", &Array[i]);
            }

            int runsCount = 10;
            for (int i = 1; i <= runsCount ; i++){

                time =  clock();
                // cout << Array.size() - 1;
                Quick_Sort(Array, 0 , Array.size() - 1);
                time = clock() - time;
                av_time +=time;
                if(!Check_Arr(Array))
                    cout << "\nMassive " << m_size << " with range " << m_range << " was not sorted";

            }
            fclose(f); 
            if (Check_Arr(Array))
            cout << "\nMassive " << m_size << " with range " << m_range << " was sorted in average time of " << av_time/runsCount << " ms.";
        }
    }

    return 0;
}