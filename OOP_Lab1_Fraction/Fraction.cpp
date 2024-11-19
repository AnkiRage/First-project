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
        int flag = 1, i;
        while(flag){
        for (i = 0; i < Elem.size(); i++){
            if (Higher % Elem[i] == 0 && Lower % Elem[i] == 0){
                Higher /= Elem[i];
                Lower /= Elem[i];
                break;
            }
        }
        if (i == (Elem.size() - 1)) flag = 0; /////????????//////
        }
    }
    
    void Fraction::Int_to_Double()const{
        double C = (double)Higher / (double)Lower;
        cout << "\n" << (double)C;
    }

    void Fraction::Swap(){
        int Buff = Higher;
        Higher = Lower;
        Lower = Buff;
    }



    
    Fraction Fraction::operator+(const Fraction& B) {
        if(Lower == B.Lower){
           Higher += B.Higher;
           return *this;
        }
        Higher = Higher * B.Lower + B.Higher * Lower;
        Lower *= B.Lower;
        return *this;  
  
    
    }

    Fraction Fraction::operator-(const Fraction& B){
        if(Lower == B.Lower){
           Higher -= B.Higher;
           return *this;
        }
        Higher = Higher * B.Lower - B.Higher * Lower;
        Lower *= B.Lower;
        return *this;  
    }

    Fraction Fraction::operator*(const Fraction& B){
        Higher *= B.Higher;
        Lower *= B.Lower;
        return *this;
    }
    Fraction Fraction::operator/(const Fraction& B){
        Higher *= B.Lower;
        Lower *= B.Higher;
        return *this;
    }


    bool Fraction::operator>(const Fraction B)const{
        if(Lower == B.Lower){
            if(Higher > B.Higher) 
            return true;
            else return false;
        }
        if (Higher * B.Lower > B.Higher * Lower)
        return true;
        else return false;
    }

    bool Fraction::operator<(const Fraction B)const{
        if(Lower == B.Lower){
            if(Higher < B.Higher) 
            return true;
            else return false;
        }
        if (Higher * B.Lower < B.Higher * Lower)
        return true;
        else return false;
    }

    bool Fraction::operator==(const Fraction B)const{
        if(Lower == B.Lower){
            if(Higher == B.Higher) 
            return true;
            else return false;
        }
        if (Higher * B.Lower == B.Higher * Lower)
        return true;
        else return false;
    }

    bool Fraction::operator!=(const Fraction B)const{
        if(Lower == B.Lower){
            if(Higher != B.Higher) 
            return true;
            else return false;
        }
        if (Higher * B.Lower != B.Higher * Lower)
        return true;
        else return false;
    }

    
    //a += b -> a.operator+=(b);

    // Fraction& operator>(const Fraction B);
    // Fraction& operator<(const Fraction B);
    // Fraction& operator==(const Fraction B);
    // Fraction& operator!=(const Fraction B);
