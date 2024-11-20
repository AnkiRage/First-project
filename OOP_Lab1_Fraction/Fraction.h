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
    double To_Double()const;
    void Swap();

    Fraction operator+(const Fraction& B)const;
    Fraction operator-(const Fraction& B)const;
    Fraction operator*(const Fraction& B)const;
    Fraction operator/(const Fraction& B)const;


    bool operator>(const Fraction B)const;
    bool operator<(const Fraction B)const;
    bool operator==(const Fraction B)const;
    bool operator!=(const Fraction B)const;

private:
    int Lower;
    int Higher;
};
