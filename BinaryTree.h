//
// Created by Stephanie Spears on 3/3/18.
//

#ifndef LIVECODINGPROBLEMS_BINARYTREE_H
#define LIVECODINGPROBLEMS_BINARYTREE_H

//struct Node{
//	int data;
//	Node *left;
//	Node *right;
//};
struct Node{
	int key_val;
	Node *left;
	Node *right;
};

class BinaryTree{
public:
	BinaryTree();
	~BinaryTree();

	void add(int key, Node *leaf);
	Node *search(int key, Node *leaf);
	void del();
	void del(Node *leaf);


	Node *root;

};

#endif //LIVECODINGPROBLEMS_BINARYTREE_H


//The difference between pass-by-reference and pass-by-pointer is that pointers can be NULL or reassigned whereas references cannot. Use pass-by-pointer if NULL is a valid parameter value or if you want to reassign the pointer. Otherwise, use constant or non-constant references to pass arguments.