//stack implementation using linked list and structures in c++


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;
};
node* head = NULL;

int push(int value){
	
	node* temp = head;
	node* new_node = new node;
	new_node->data = value;
	new_node->next = NULL;
	 
	if(head!=NULL){
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = new_node;
		
	}
	else
		head = new_node;
	
	return 0;
}

int pop(){

	if(head->next!=NULL){

		node* temp = head;
		while(temp->next->next!=NULL)
			temp = temp->next;
		//node *t = temp->next;
		free(temp->next);
		temp->next = NULL;
		//cout<<"memory check"<<t->data<<endl;
		
	}
	else{
		free(head);
		head=NULL;
	}

	return 0;
}

int display(){

	if(head!=NULL){
		node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}
	else
		cout<<"Nothing to display";

	cout<<endl;
}

int main(){
		
	
	push(10);
	push(20);
	push(30);
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();

	return 0; 
}