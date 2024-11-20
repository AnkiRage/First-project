#include "Fraction.h"


#include <iomanip>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using std::cout;
using std::vector;

Fraction::Fraction(int h, int l){
    Higher = h;
    Lower = l;
}

void  Fraction::Set_Higher(int m){
    Higher = m;
}

void  Fraction::Set_Lower(int m){
    if (m < 0) {
        Higher *= -1;
        m *= -1;
    }
    Lower = m;
}

int Fraction::Get_Higher() const{
    return Higher;
}

int  Fraction::Get_Lower() const {
    return Lower;
}

void Fraction::Out() const{
    cout << "\n" << Higher << " / " << Lower;
}

void Fraction::Set_Fraction(int H, int L){
    Set_Higher(H);
    Set_Lower(L);
}

void Fraction::Reduction(){
    int A_El, B_El, buff;
    if (Higher == Lower){
        Higher = Lower = 1;
        return;
    }
    else if ( Higher > Lower){
        A_El = Higher;
        B_El = Lower;
    }
    else {
        A_El = Lower;
        B_El = Higher;
    }

    while(A_El % B_El != 0) {
        buff = A_El % B_El;
        A_El = B_El;
        B_El = buff;
    }

    Higher /= B_El;
    Lower /= B_El;
}

double Fraction::To_Double()const{
    double C = (double)Higher / (double)Lower;
    return C;
}

void Fraction::Swap(){
    int Buff = Higher;
    Higher = Lower;
    Lower = Buff;
}




Fraction Fraction::operator+(const Fraction& B)const {
    int New_Higher = Higher * B.Lower + B.Higher * Lower;
    int New_Lower = Lower * B.Lower;
    return Fraction(New_Higher, New_Lower);  
}

Fraction Fraction::operator-(const Fraction& B)const {
    int New_Higher = Higher * B.Lower - B.Higher * Lower;
    int New_Lower = Lower * B.Lower;
    return Fraction(New_Higher, New_Lower);  
}

Fraction Fraction::operator*(const Fraction& B)const{
    int New_Higher = Higher * B.Higher;
    int New_Lower = Lower * B.Lower;
    return Fraction(New_Higher, New_Lower);
}
Fraction Fraction::operator/(const Fraction& B)const{
    int New_Higher = Higher * B.Lower;
    int New_Lower = Lower * B.Higher;
    return Fraction(New_Higher, New_Lower);
    
}


bool Fraction::operator>(const Fraction B)const{
    return (Higher * B.Lower > B.Higher * Lower);
}

bool Fraction::operator<(const Fraction B)const{
    return (Higher * B.Lower < B.Higher * Lower);
}

bool Fraction::operator==(const Fraction B)const{
    return (Higher * B.Lower == B.Higher * Lower);
}

bool Fraction::operator!=(const Fraction B)const{
    return (Higher * B.Lower != B.Higher * Lower);
}


//a += b -> a.operator+=(b);

// Fraction& operator>(const Fraction B);
// Fraction& operator<(const Fraction B);
// Fraction& operator==(const Fraction B);
// Fraction& operator!=(const Fraction B);
