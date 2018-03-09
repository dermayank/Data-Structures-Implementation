#include <iostream>
#include <vector>
using namespace std;

int enqueue(int *stack, int val, int count){

	stack[count] = val;
	cout<<"pushed "<<stack[count]<<endl;
	count++;
	return count;
}

int dequeue(int *stack, int count){

	if(count>1){
		int temp = stack[count-1];
		count = dequeue(stack, count-1);						//recursively popping element of the stack
		stack[count] = temp;									// pushing back the popped elements onto the stack except the first element of stack
		count++;
	}
	else{
		count--;
		cout<<"popped "<<stack[count]<<endl;
	}
	return count;
}

int display(int *stack, int count){

	for(int i=0; i<count; i++)
		cout<<stack[i]<<" ";
	cout<<endl;
}


int main(){

	int stack[100], count=0;
	count = enqueue(stack,4,count);
	count = enqueue(stack,5,count);
	count = enqueue(stack,6,count);
	count = enqueue(stack,7,count);
	count = enqueue(stack,8,count);
	count = enqueue(stack,9,count);

	display(stack,count);

	count = dequeue(stack,count);
	count = dequeue(stack,count);
	count = dequeue(stack,count);
	
	display(stack,count);
	
	return 0;
}
