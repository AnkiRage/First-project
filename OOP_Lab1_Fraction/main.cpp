#include "Fraction.h"

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>

using std::cout;
using std::cin;

int main()
{   
    // int A = 4;
    // int B = 3;
    // // double AA = A;
    // // double BB = B;
    // double C = (double)A / (double)B;
    // cout << (double)C;
    Fraction A(7,21);
    A.Reduction();
    A.Out();

    for (int num = 1; num <= 4000; ++num) {
        for (int den = 1; den <= 4000; ++den) {
            Fraction tmp(num, den);
            tmp.Reduction();
            if ((tmp.To_Double() - double(num) / den)) {
                std::cout << num << '/' << den << ": " << (tmp.To_Double() - double(num) / den) << "\n";
            }
        }
    }
    return 0; 
    //12 / 15: 3
    //15 % 12 = 3
    //12 % 3 = 0
}