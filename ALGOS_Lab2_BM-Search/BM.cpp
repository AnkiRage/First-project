#include "BM.h"


#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>

using std::cout;

int Find_First(string Text, string Substring){
 if (Substring.empty()) {
        return -1;
    }
    int TAB[256], Substring_lenght, Text_lenght, k, j, flag = 0, b = 1;
	Text_lenght = Text.size();
	Substring_lenght = Substring.size();

	for (int i = 0; i < 256; i++)
		TAB[i] = Substring_lenght;
	for (int i = 0; i < Substring_lenght - 1; i++)
		TAB[Substring[i]] = Substring_lenght - 1 - i;

	int i =  Substring_lenght - 1;

	while (i <= Text_lenght) {
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

vector<int> Find_All(string Text, string Substring, int start, int end, vector<int>& Found){
    if (start < 0 || end >= Text.size() || start > end || Substring.empty()) {
        return Found;
    }
    int TAB[256], Substring_lenght, Text_lenght, k, j, flag = 0, b = 1;
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
            Found.push_back(k + 1) ;
            i += Substring_lenght;
        }
        else{
            i += TAB[Text[i]];
        }
	}
    return Found;
}
