//
// Created by Stephanie Spears on 2/20/18.
//

#include <iostream>
#include "SinglyLinkedList.h"
#include "UserInterface.h"


using namespace std;


class Node{
    int data;
    Node* next;

public:
    Node(){};
    void SetData(int aData){ data = aData; };
    void SetNext(Node* aNext){ next = aNext; };
    int Data(){ return data; };
    Node* Next(){ return next; };
};

class List {
    Node *head;
public:
    List(){ head = NULL; };
    void Print();
    void Append(int data);
    void Delete(int data);
};

void List::Print(){
    //Temp pointer
    Node *tmp = head;

    //No Nodes
    if(tmp == NULL){
        cout << "EMPTY" << endl;
        return;
    }

    //One node in list
    if(tmp->Next() == NULL){
        cout << tmp->Data();
        cout << " --> ";
        cout << "NULL" << endl;
    }
    else{
        //Parse and print the list
        do{
            cout << tmp->Data();
            cout << " --> ";
            tmp = tmp->Next();
        }
        while(tmp != NULL);
        cout << "NULL" << endl;
    }
}

void List::Append(int data){
    //create new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);

    //Create temp pointer
    Node *tmp = head;

    if(tmp != NULL){
        //Nodes already present in the list
        //Parse to end of list
        while(tmp->Next() != NULL){
            tmp = tmp->Next();
        }

        //Point last node to the new node
        tmp->SetNext(newNode);
    }
    else{
        //First node in list
        head = newNode;
    }
}

void List::Delete(int data) {
    //create temp pointer
    Node *tmp = head;

    //no nodes
    if(tmp == NULL){
        return;
    }


    //last node of the list
    if(tmp->Next() == NULL){
        delete tmp;
        head = NULL;
    }
    else{
        //parse through nodes
        Node *prev = NULL; //changed
        do{
            if (tmp->Data() == data){
                break;
            }
            prev = tmp;
            tmp = tmp->Next();
        }
        while(tmp != NULL);
        //Adjust the pointers
        if(prev != NULL && tmp != NULL){ //changed
            prev->SetNext(tmp->Next());
        }
        if(head == tmp){
            head = tmp->Next();
        }

        //delete current node
        if(tmp!=NULL){ //changed
            delete tmp;

        }
    }
}





void SinglyLinkedList(){
    //New list
    List list;
    char command;

    while(command != 4){
        cout << "1) Append \n2) Delete \n3) Print \n4) Quit" << endl;
        command = readInCommand();
        int value;
        switch(command){
            case 1: cout << "Append value: ";
                cin >> value;
                list.Append(value);
                list.Print();
                break;
            case 2: cout << "Delete value: ";
                cin >> value;
                list.Delete(value);
                list.Print();
                break;
            case 3: cout << "Printing..." << endl;
                list.Print();
                break;
            default: cout << endl << "Invalid Choice." << endl;
                break;
        }
    }

};