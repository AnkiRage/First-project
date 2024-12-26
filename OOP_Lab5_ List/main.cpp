#include "List.h"
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>

using std::cout;
using std::cin;

int main()
{
List<int> myList;
myList.Add_to_Head(10);
myList.Add_to_Tail(20);
myList.Add_to_Tail(30);

cout << myList;

cout << myList.Find_Key_Iter(30);
cin >> myList;
cout << myList;
}