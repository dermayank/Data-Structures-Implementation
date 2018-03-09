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

node* insert(node* root, int val){
	
	if(root == NULL)
		root = create_child(val);
	else{
		if(root->data > val)
			root->left = insert(root->left, val);
		else
			root->right = insert(root->right, val);
	}
	return root;
}

int preorder(node *root)
{
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	return 0;
}

int inorder(node *root){

	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
	return 0;
}

int postorder(node *root){

	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
	return 0;
}

node* next_element(node* root){
	
	while(root->left!=NULL)
		root = root->left;

	return root;
}


node* delete_node(node* root, int val){
	
	if(root!=NULL){
		if(root->data==val){
			
			if(root->left==NULL){
				delete root;
				return root->right;
			}
			else if(root->right==NULL){
				delete root;
				return root->left;
			}
			else{
				node* temp = next_element(root->right);
				root->data = temp->data;

				root->right = delete_node(root->right,temp->data);
			}
		}
		else{
			if(root->data>val)
				root->left = delete_node(root->left, val);
			else
				root->right = delete_node(root->right, val);
		}
	}
	return root;
}

int main()
{
	node* root;
	root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

    root = delete_node(root,50);
    inorder(root);
    cout<<endl;

    return 0;
}