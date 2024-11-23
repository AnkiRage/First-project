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
    // int buf;
    // vector<int> Add;
    // for(int count = 0; ; count++){
    //     if (count%2 == 1)
    //         buf = 8 * pow(2, count) - 6 * pow(2, (count + 1) / 2);
    //     else  buf = 9 * pow(2, count) - 9 * pow(2, count / 2);
    //     // cout << " \nbuf = " << buf;
    //     if (buf >= Arr.size()) 
    //         break;
    //     Add.push_back(buf);
    // }
    // for ( int f = Add.size() - 1; f >= 0 ; f-- ){
    // int s = Add[f];
    //     for (int i = s; i < Arr.size(); ++i) {
    //         for (int j = i - s; j >= 0 && Arr[j] > Arr[j + s]; j -= s) {
    //             int temp = Arr[j];
    //             Arr[j] = Arr[j + s];
    //             Arr[j + s] = temp;
    //         }
    //     }
    // }





    if (Arr.size() == 0) return;
      vector<int> Add; // Массив шагов
    int buf;

    // Генерация последовательности Седжвика
    for (int count = 0;; ++count) {
        if (count % 2 == 1)
            buf = 8 * (1 << count) - 6 * (1 << ((count + 1) / 2));
        else
            buf = 9 * (1 << count) - 9 * (1 << (count / 2));
        
        if (buf >= Arr.size()) break; // Остановка, если шаг больше размера массива
        Add.push_back(buf);
    }

    // Итерация по шагам в обратном порядке
    for (int f = Add.size() - 1; f >= 0; --f) {
        int s = Add[f];
        for (int i = s; i < Arr.size(); ++i) {
            int temp = Arr[i];
            int j = i;
            while (j >= s && Arr[j - s] > temp) {
                Arr[j] = Arr[j - s];
                j -= s;
            }
            Arr[j] = temp;
        }
    }
}

void Sort_Shell_Hibbard(vector<int>& Arr){
    vector<int> Add;
    for( int  count = 0; (pow(2, count) - 1) < Arr.size(); count++){
        Add.push_back(pow(2, count) - 1);
    }
    for ( int f = Add.size() - 1; f >= 0 ; f-- ){
    int s = Add[f];
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