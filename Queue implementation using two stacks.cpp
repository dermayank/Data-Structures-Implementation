#include <iostream>
using namespace std;

int count = 0;

int enqueue(int *stack1, int val){
	
	stack1[count] = val;
	count +=1;
	
	return 0;
}

int dequeue(int *stack1, int *stack2){

	if(count>0){
		for(int i=0; i<count; i++){
			stack2[count-i-1]= stack1[i];
		}
		count--;
		for(int i=0; i<count; i++){
			stack1[i] = stack2[count-i-1];
		}
	}
	return 0;
}

int display(int *stack1){

	for(int i=0; i<count; i++)
		cout<<stack1[i]<<" ";
	cout<<endl;
}

int main()
{
	int stack1[100],stack2[100];

	enqueue(stack1,3);
	enqueue(stack1,4);
	enqueue(stack1,5);
	enqueue(stack1,6);
	enqueue(stack1,7);
	display(stack1);
	dequeue(stack1,stack2);
	dequeue(stack1,stack2);
	display(stack1);

	return 0;
}
