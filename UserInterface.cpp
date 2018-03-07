//
// Created by Stephanie Spears on 2/20/18.
//
#include <iostream>

#include "UserInterface.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "HighestIndex.h"
#include "BinaryTree.h"

using namespace std;

int readInt(const char prompt[]){
    int intVal;
    cout << endl << prompt;
    cin >> intVal;

    while(!cin){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Illegal integer. Try again: ";
        cin >> intVal;
    }
    cin.ignore(100, '\n');
    return intVal;
}

double readDouble(const char prompt[]){
    double doubleVal;
    cout << endl << prompt;
    cin >> doubleVal;
    while (!cin) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Illegal floating point value. Please try again: ";
        cin >> doubleVal;
    }
    cin.ignore(100, '\n');
    return doubleVal;
}

char readChar(const char prompt[])
{
    char aChar;
    cout << endl << prompt;
    cin >> aChar;
    cin.ignore(100, '\n');
    return aChar;
}

string readString(const char prompt[], string aString)
{
    cout << endl << prompt;
    cin >> aString;
    while (!cin) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << endl << prompt;
        cin >> aString;
    }
    cin.ignore(100, '\n');
    return aString;
}

void displayMenu(){
    cout << endl;
    cout << "Live Coding Practice" << endl << endl;
    cout << "1) Singly Linked List" << endl;
    cout << "2) Doubly Linked List" << endl;
    cout << "3) Highest Index in Array" << endl;
    cout << "4) Binary Tree" << endl;
//    cout << "5) Hash Map" << endl;
    cout << "9) QUIT" << endl << endl;

}

int readInCommand(){
    int cmd;
    cmd=readInt("Enter Menu Option: ");
    cout << endl;
    return (cmd);
}

void processCommand(char command){
    switch(command){
        case 1: SinglyLinkedList();
            break;
        case 2: DoublyLinkedList();
            break;
        case 3: HighestIndex();
            break;
        case 4: BinaryTree();
            break;
//        case 5: HashMap();
//            break;
        case 9: cout << "Quitting..." << endl;
        default: cout << endl << "Invalid Choice." << endl;
            break;
    }
}