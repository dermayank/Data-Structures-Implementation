#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define null NULL
struct node{
	int data;
	node* next;
};

node* head = null;
node* tail = null;

int enqueue(int value)
{
	node* data_node = new node;
	data_node->data = value;
	data_node->next = null;

	if(head==null){
		head = tail = data_node;
		
	}
	else{
		tail->next = data_node;
		tail = tail->next;
	}

}

int dequeue()
{
	delete head;			//dangling pointer created because of deletion of memory
	head = head->next;	
}

int display(){
	node* temp = head;
	while(temp!=null){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
	return 0;
}


int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	display();
	dequeue();
	dequeue();
	display();


	return 0;
}

