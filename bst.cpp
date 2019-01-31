#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

struct node
{
	int key;
	struct node *right;
	struct node *left;
};

//Create new BST tree
struct node *newTree(int value){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = value;
	temp->right = temp->left = NULL;

	return temp;
}

//Inorder tree traversal (left, root, right)
void inorder(struct node *root){

	if ( root != NULL ){
		inorder(root->left);
		cout<<root->key<<"\n";
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int value){

	//if node struct passed is null then create new tree
	if(node == NULL)
		return newTree(value);

	//if value is less than the current node key then insert to left
	if(value < (node->key))
		node->left = insert(node->left, value);

	//if value is greater than the current node key then insert to thr right
	else if (value> node->key)
		node->right = insert(node->right, value);

	return node;
}

int main()
{
	struct node *root = NULL;
	root = insert(root, 5);
	insert(root, 3);
	insert(root, 2);
	insert(root, 4);
	insert(root, 7);
	insert(root, 1);
	insert(root, 8);
    insert(root, 1);
	insert(root, 8);

	inorder(root);

	return 0;
}