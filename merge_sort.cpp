 #include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int merge(vi &arr, int start, int end){

	int mid = (start+end)/2;
	int i=start, j=mid+1, k=start;
	int n = arr.size();
	vi temp_arr;
	temp_arr = arr;

	while((i<=mid)&&(j<=end)){
		if(arr[i]<arr[j]){
			temp_arr[k] = arr[i];
			i++;
		}
		else{
			temp_arr[k] = arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid){
		temp_arr[k] = arr[i];
		k++;
		i++;
	}
	while(j<=end){
		temp_arr[k] = arr[j];
		k++;
		j++;
	}

	arr = temp_arr;
	return 0;
}

int merge_sort(vi &arr, int start, int end){

	if(end > start){
		int mid = (start+end)/2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		merge(arr, start,end);
	}
	return 0;
}
int main()
{
	vi arr{7,8,1,5,2,9,78,10,3,1};
	merge_sort(arr, 0, arr.size()-1);

	for(int i=0; i<arr.size(); i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	return 0;
}	