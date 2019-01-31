#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

struct node
{
	string key;
	struct node *right;
	struct node *left;
};

//Create new BST tree
struct node *newTree(string value){

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

//Preorder tree traversal (left, root, right)
void preorder(struct node *root){

	if ( root != NULL ){
		cout<<root->key<<"\n";
		preorder(root->left);
		
		preorder(root->right);
	}
}

void postOrder(struct node *root){

	if(root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->key<<"\n";

	}
}

struct node* insert(struct node* node, string value){

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
	string exp = "(a+b)*c-(d-e)*f/g";
	string::iterator it = exp.begin();

	string expstr(1, *it);
	root = insert(root, expstr);

	while(it != exp.end()){
    ++it;
	string expstr(1, *it);
	insert(root, expstr);
		
	}

	// root = insert(root, "F");
	// insert(root, "B");
	// insert(root, "A");
	// insert(root, "C");
	// insert(root, "D");
	// insert(root, "E");
	// insert(root, "G");
 //    insert(root, "H");
	// insert(root, "I");

	cout<<"\nInorder Traversal: ";
	inorder(root);
	cout<<"\nPreorder Traversal: ";
	preorder(root);
	cout<<"\npostOrder Traversal: ";
	postOrder(root);

	return 0;
}