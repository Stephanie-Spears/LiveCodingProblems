//
// Created by Stephanie Spears on 2/20/18.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include "DoublyLinkedList.h"
using namespace std;


struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
public:
    LRUCache(int c) { cp = c; }

    void set(int k, int v){
        Node *N;
        if(mp.empty()){  //no nodes
            N = new Node(k, v);
            tail = head = N;
            mp[k] = N;
            return;
        }

        auto it = mp.find(k); //search map for key

        if(it != mp.end()){ //if key is in hash table
            it->second->value = v; //update value
            if(head == it->second){ //if second node is head node
                return;
            }

            it->second->prev->next = it->second->next;

            if(tail == it->second){ //if second node is tail node
                tail = tail->prev;
            }
            else{ //if node is between head and tail nodes
                it->second->next->prev = it->second->prev;
            }
            it->second->next = head; //update nodes so next points to head?
            it->second->prev = NULL; //update previous node pointer to NULL, erasing
            head->prev = it->second; //update the head's 'previous' node to new 'second'
            head = it->second; //update head to 'second'
        }
        else{ //not in hash table
            N = new Node(head->prev, head, k, v); //new node
            head->prev = N;
            head = N;
            mp[k] = N;
            if(mp.size() > cp){ //check capacity
                tail=tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next=NULL;
            }

        }
    }
    int get(int k){
        auto it = mp.find(k);
        if(it != mp.end()){
            return it->second->value;
        }
        return -1;
    }

    void Print() {
        //play around with these-->you can see when you print sequential ones that the nodes link memory addresses for next/prev etc.
        for (auto elem : mp){
            cout << elem.first << " " << elem.second->value << " " << elem.second->key << " " << elem.second->next << " " << elem.second->prev << endl;
        }
    }
//        for(auto it = (mp.begin(), mp.end())){
//            cout << it->first << " " << it->second << " " << endl;
//        };

};

void DoublyLinkedList(){
    //n = number of queries
    int n = 10;
    //capacity is the size of the Least Recently Used Cache list
    cout << "Enter the size of the Cache: ";
    int capacity;
    cin >> capacity;

    LRUCache l(capacity);
    for(int i=0;i<n;i++) {
//        Enter either 'set num1 num2' to specify a new key/value store in the cache, or 'get num1' to specify that you want to search for a key in the cache
        cout << "Enter 'set num1 num2', 'get num1', or 'print' :";
        string command;
        cin >> command;
        if(command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
        else if (command == "print"){
            l.Print();
        }
    }
};
