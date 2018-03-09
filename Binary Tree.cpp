//	                                                                                    7
//	                                                                                  /   \
//	        Sample Binary Tree -                                                     5     8
//	                                                                                / \   / \
//	                                                                               9  10  1  3

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left = NULL;
	node* right = NULL;
};

node* create_child(int val){

	node* child = new node;
	child->data = val;
	return child;
}

int preorder(node* root)
{
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	return 0;
}

int inorder(node* root)
{
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
	return 0;
}

int postorder(node* root)
{
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
	return 0;
}

int main()
{
	node* root;

	root = create_child(7); 															  
	root->left = create_child(5);														   		
	root->right = create_child(8);														   
	root->left->left = create_child(9);													   
	root->left->right = create_child(10);                                                                                                
	root->right->left = create_child(1);
	root->right->right = create_child(3);

	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;

	return 0;
}

