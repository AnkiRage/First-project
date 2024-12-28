#include "BM.h"


#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>

using std::cout;

int Find_First(const string& Text,const string& Substring , int start, int end){
    if (start < 0 || end >= Text.size() || start > end || Substring.empty()) {
        return - 1;
    }
    int TAB[256], Substring_lenght, Text_lenght, k, j, flag = 0;
	Text_lenght = Text.size();
	Substring_lenght = Substring.size();

	for (int i = 0; i < 256; i++)
		TAB[i] = Substring_lenght;
	for (int i = 0; i < Substring_lenght - 1; i++)
		TAB[Substring[i]] = Substring_lenght - 1 - i;

	int i = start + Substring_lenght - 1;

	while (i <= end) {
        k = i;
        j = Substring_lenght - 1;
        while (j >= 0 && Text[k] == Substring[j]) {
            k--;
            j--;
        }
        if(j < 0) {
            return k + 1;
        }
        else{
            i += TAB[Text[i]];
        }
	}
    return -1;
}

void Find_All(const string& Text,const string& Substring, int start, int end, vector<int>& Found){
    if (start < 0 || end >= Text.size() || start > end || Substring.empty()) {
        return;
    }
    int Substring_lenght = Substring.size();
    int temp = start;
    while (temp <= end){
        int value = Find_First(Text, Substring, temp, end);
        if(value == -1)
            return;
        Found.push_back(value);
        temp = value + 1;
    }
}
