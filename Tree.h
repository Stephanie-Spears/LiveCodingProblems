//
// Created by Stephanie Spears on 3/5/18.
//

#ifndef LIVECODINGPROBLEMS_TREE_H
#define LIVECODINGPROBLEMS_TREE_H

// bst.cpp
// binary search tree
// FB - 201101263
#include<iostream>
#include<iomanip> //width()
using namespace std;
#define width_unit 5


class Tree
{
private:
	class Node
	{
	public:
		int data;
		Node *left, *right;
		Node(int d=0) //constructor
				:data(d), left(NULL), right(NULL) {}
	};

	Node *root;
	Node * trav(int, Node * &);
	void chop(Node * N);
	void copy(Node * N);
	void print(ostream &, Node *, int) const;
	void print(Node *, int) const;

public:
	Tree(void); //constructor
	~Tree(void); //destructor
	bool find(int);
	void insert(int);
	void remove(int);
	bool empty(void) const;
	Tree(const Tree &); //copy constructor
	const Tree & operator=(const Tree &); //assignment operator overload
	friend ostream & operator<<(ostream &, const Tree &);
};

#endif //LIVECODINGPROBLEMS_TREE_H
