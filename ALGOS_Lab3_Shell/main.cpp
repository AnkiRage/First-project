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

            for (int i = 1; i <= 3 ; i++){

                time =  clock();
                Sort_Shell_Usual(Array);
                // time_seconds = (clock() - time) * CLOCKS_PER_SEC;
                time = clock() - time;
                av_time +=time;
                if(!Check_Arr(Array))
                    cout << "\nMassive " << m_size << " with range " << m_range << " was not sorted";

            }
            fclose(f); 
            cout << "\nMassive " << m_size << " with range " << m_range << " was sorted in average time of " << av_time/3 << " time units.";
        }
    }

            // if(Check_Arr(Array))
            //     cout << "\nMassive " << m_size << " with range " << m_range << " was sorted in average time of " << time << " time units.";
            // else  cout << "\nMassive " << m_size << " with range " << m_range << " was not sorted";















    return 0;
}