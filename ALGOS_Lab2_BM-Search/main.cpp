#include "BM.h"

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::string;
int main()
{   
    const string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    const string substring = "tor";
    vector<int> Found ;
	int first = Find_First(text, substring, 0,text.size() - 1 );
        if (first != -1) {
        cout << "Found on: " << first << "\n";
    } else {
        cout << "Not found\n";
    }
    Find_All(text, substring, 0,text.size() - 1 ,Found);
    cout << "All found:";
    for ( int i = 0 ;i < Found.size(); i++ ){
            cout << Found[i] << ' ';
    }

	return 0;
}