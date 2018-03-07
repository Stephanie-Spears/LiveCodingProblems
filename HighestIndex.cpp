//
// Created by Stephanie Spears on 2/20/18.
//
#include <iostream>
#include "HighestIndex.h"

//The struct combines the performance and accessibility of a C-style array with the benefits of a standard container, such as knowing its own size, supporting assignment, random access iterators(pointers), etc.
//    array<int, 10> myArray {-1, -2, -3, -4, -5, -10, -9, -8, -7, -6};

//They asked me to find the index of the highest number in the array
//Then they would keep tweaking it. Highest number of a set of negative numbers, indexes if more than one number are the same


using namespace std;
void HighestIndex(){
    int someSize;
    cout << "Array Size: ";
    cin >> someSize;
    int someArray[someSize];
    // in case of high number being 0
    int high = someArray[0];
    int highIndex = 0;
    cout << "Enter array elements: ";
    for(int i=0; i<someSize; i++){
        cin >> someArray[i];
        if(high == NULL){
            high = someArray[0];
            highIndex = 0;
        }
        if(high < someArray[i]){
            high = someArray[i];
            highIndex = i;
        }
    }

    cout << "Highest Element: " << high << endl << "At Index(es): ";
    for(int i=0; i<someSize; i++){
        if(high == someArray[i]){
            cout  << i << " ";
        }
    }
}
