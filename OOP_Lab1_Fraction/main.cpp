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
    Fraction A(3,4);
    A.Int_to_Double();
    return 0; 
}