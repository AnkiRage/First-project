#include "Shell.h"

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
    clock_t time;
    int start_size = 10000, start_range = 10, m_range, m_size;
    FILE* f;
    vector<int> Array(start_size);
    for(int i = 1, size = start_size; i <=3; size*=10, i++){
        Array.resize(size);

        for (int i =1, range = start_range, av_time = 0; i <=3 ; range*=100, i++){
            string filename = "Input_data_size_" + std::to_string(size) + "_range_" + std::to_string(range) + ".txt";
            
            for (int i = 1; i <= 3 ; i++){
                f = fopen( filename.c_str(), "r");
                for(int i = 0 ; i < size; i++){
                    fscanf(f, " %d", &Array[i]);
                }
                fclose(f); 

                time =  clock();
                Sort_Shell_Hibbar(Array);
                // time_seconds = (clock() - time) * CLOCKS_PER_SEC;
                time = clock() - time;
                av_time += time;
                if(!Check_Arr(Array))
                    cout << "\nMassive " << size << " with range " << range << " was not sorted";

            }
            cout << "\nMassive " << size << " with range " << range << " was sorted in average time of " << (av_time/3.0) << " ms.";
        }
    }


    return 0;
}