#include "Set.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

CharSet::CharSet() : BoolVector(256, false){
	
}

CharSet::CharSet(char* CharArray) : BoolVector(256, false){
	int i = 0;
	while(CharArray[i] != '\0'){
		if(CharArray[i] < 0 || CharArray[i] >= 256){
			cout << "Some element can't be written in the table";
		}
		else{
		Set_Index(CharArray[i], true);
		}
		i++;
	}
}
CharSet::CharSet(const CharSet& Other) : BoolVector(Other){

}

CharSet::~CharSet(){

}

int CharSet::CharSet_Weight(){
	return Weight();
}

bool CharSet::Find_Elem(char elem){
	if (elem < 0 || elem >= 256) {
        return false; 
    }
	return Get_Index(elem);
}

char CharSet::Find_Min(){
	int i = 0;
	while(i < Get_Lenght()){
		if(Get_Index(i)){
			return i;
		}
		i++;
	}
	return '\0';
}

char CharSet::Find_Max(){
	int i = Get_Lenght() - 1;
	while(i >= 0){
		if(Get_Index(i)){
			return i;
		}
		i--;
	}
	return '\0';
}

CharSet& CharSet::operator=(const CharSet& Other){
	BoolVector::operator=(Other);
    return *this;
}

bool CharSet::operator==(const CharSet& Other){
	for(int i = 0; i < Get_Lenght(); i++){
		if(Get_Index(i) != Other.Get_Index(i))
			return false;
	}
	return true;
}

bool CharSet::operator!=(const CharSet& Other){
	return !(*this == Other);
}

CharSet& CharSet::operator+=(const char& element){
	Set_Index(element, true);
	return *this;
}

CharSet CharSet::operator+(const char& element){
	CharSet Temp(*this);
	Temp += element;
	return Temp;
}

CharSet& CharSet::operator-=(const char& element){
	Set_Index(element, false);
	return *this;
}

CharSet CharSet::operator-(const char& element){
	CharSet Temp(*this);
	Temp -= element;
	return Temp;
}

CharSet& CharSet::operator|=(const CharSet& Other){ /// Объединение
	for(int i = 0; i < Get_Lenght(); i++){
		if(Other.Get_Index(i)){
			Set_Index(i, true);
		}
	}
	return *this;
}

CharSet CharSet::operator|(const CharSet& Other){
	CharSet Temp(*this);
	Temp |= Other;
	return Temp;
}

CharSet& CharSet::operator&=(const CharSet& Other){/// Перечесение
	for(int i = 0; i < Get_Lenght(); i++){
		if(Other.Get_Index(i) == Get_Index(i)){
			Set_Index(i, true);
		}
		else{
			Set_Index(i, false);
		}
	}
	return *this;
} 

CharSet CharSet::operator&(const CharSet& Other){
	CharSet Temp(*this);
	Temp &= Other;
	return Temp;
}

CharSet& CharSet::operator/=(const CharSet& Other){ /// Разность
	for(int i = 0; i < Get_Lenght(); i++){
		if(Other.Get_Index(i) == Get_Index(i)){
			Set_Index(i, false);
		}
	}
	return *this;
}

CharSet CharSet::operator/(const CharSet& Other){
	CharSet Temp(*this);
	Temp /= Other;
	return Temp;
}
CharSet CharSet::operator~(){
	CharSet Temp(*this);
	Temp.Inverse_All();
	return Temp;
}

ostream& operator<<(ostream& os, const CharSet& Set) {
    os << "{";
    bool first = true;
    for (int i = 0; i < Set.Get_Lenght(); i++) {
        if (Set.Get_Index(i)) {
            if (!first) {
                os << ", "; 
            }
            os << static_cast<char>(i); 
            first = false;
        }
    }
    os << "}";
    return os;
}

istream& operator>>(istream& is, CharSet& Set) {
    string input;
    is >> input; 
    for (char c : input) {
        Set += c; 
    }
    return is;
}