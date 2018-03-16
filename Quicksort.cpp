#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int partation(vi &arr, int start, int end){
	//cout<<"in here "<<start<<" "<<end<<endl;
	int m = start;

	for(int i=start; i<end; i++){
		if(arr[end] >= arr[i]){
			int temp = arr[i];
			arr[i] = arr[m];
			arr[m] = temp;
			m++;
		}
	
	}
	int temp = arr[m];
	arr[m] = arr[end];
	arr[end] = temp;
	//cout<<"return "<<m<<endl;
	return m;
}

int quick_sort(vi &arr, int start, int end){

	if(end > start){
		int pivot = partation(arr, start, end);
		quick_sort(arr, start, pivot-1);
		quick_sort(arr, pivot, end);
	}
	return 0;
}

int main()
{
	vi arr{3,5,2,9,33,42,13,17};
	quick_sort(arr, 0, arr.size()-1);

	for(int i=0; i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
