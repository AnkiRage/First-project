#pragma once

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <vector>

using std::vector;

class Fraction{
public:
    Fraction(int higher = 0, int lower = 1);

    void Set_Higher(int m);
    void Set_Lower(int m);
    int Get_Higher() const;
    int Get_Lower() const;
    void Out() const;
    void Set_Fraction(int H, int L);
    void Reduction();
    void Int_to_Double()const;
    void Swap();

    Fraction operator+(const Fraction& B);
    Fraction operator-(const Fraction& B);
    Fraction operator*(const Fraction& B);
    Fraction operator/(const Fraction& B);


    bool operator>(const Fraction B)const;
    bool operator<(const Fraction B)const;
    bool operator==(const Fraction B)const;
    bool operator!=(const Fraction B)const;

private:
    vector<int> Elem {2 ,3 ,5 ,7 , 11, 13, 17, 19, 23, 29};
    int Lower;
    int Higher;
};
