//
// Created by Stephanie Spears on 3/3/18.
//
#include <iostream>
#include "BinaryTree.h"
#include "UserInterface.h"
# include <cstdlib>

using namespace std;


BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::~BinaryTree() {
	del();
}

void BinaryTree::del(Node *leaf){
	if(leaf!= nullptr){
		del(leaf->left);
		del(leaf->right);
		delete leaf;
	}
}

void BinaryTree::add(int key, Node *leaf){
	if(key < leaf->key_val){
		if(leaf->left != nullptr){
			add(key, leaf->left);
		}
		else{
			leaf->left=new Node;
			leaf->left->key_val=key;
			leaf->left->left= nullptr;
			leaf->left->right= nullptr;
		}
	}
	else if(key>=leaf->key_val){
		if(leaf->right!= nullptr){
			add(key, leaf->right);
		}
		else{
			leaf->right=new Node;
			leaf->right->key_val=key;
			leaf->right->left= nullptr;  //Sets the left child of the child node to null
			leaf->right->right= nullptr;
		}
	}
}

Node *BinaryTree::search(int key, Node *leaf)
{
	if(leaf!= nullptr)
	{
		if(key==leaf->key_val)
			return leaf;
		if(key<leaf->key_val)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return nullptr;
}