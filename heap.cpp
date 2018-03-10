#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef vector<int> vi;

int max_heapify(vi &heap, int index, int n){

	int left = 2*index+1;
	int right = 2*index+2;
	int largest = index;

	if(heap[left] > heap[largest] && left < n)
		largest = left;

	if(heap[right] > heap[largest] && right<n)
		largest = right;
		
	if(largest!=index){
		int temp = heap[index];
		heap[index] = heap[largest];
		heap[largest] = temp;
		max_heapify(heap,largest,n);
	}

	return 0;
}

int heap_sort(vi &heap, vi &sorted_array, int n){

	for(int i=1;i<=n;i++){

		sorted_array.push_back(heap[0]);
		heap[0] = heap[n-i];
		max_heapify(heap,0,n-i);
	}

}

int build_heap(vi &heap ,int n)
{
	
	for(int i=(n/2)-1;i>=0;i--)
		max_heapify(heap,i,n);
	return 0;
}

int main()
{
	vi heap, sorted_array;
	heap.push_back(5);
	heap.push_back(7);
	heap.push_back(1);
	heap.push_back(9);
	heap.push_back(2);
	heap.push_back(3);
	heap.push_back(10);
	heap.push_back(4);
	heap.push_back(6);
	heap.push_back(13);

	int n = heap.size();
	build_heap(heap, n);

	cout<<"Heap printed levelwise after heap is built:"<<endl;
	for(int i=0;i<n;i++)
		cout<<heap[i]<<" ";
	cout<<endl<<endl;

	heap_sort(heap, sorted_array, n);
	cout<<"Sorted elements after heap sort:"<<endl;
	for(int i=n-1;i>=0;i--)
		cout<<sorted_array[i]<<" ";
	cout<<endl;

	return 0;
}