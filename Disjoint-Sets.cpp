#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int find_parent(vi &parent, int val){
	if (parent[val] != val)
		parent[val] = find_parent(parent, parent[val]);
	
	return parent[val];
}

int find_union(vi &parent, vi &rank, int x, int y){

	int x_parent = find_parent(parent, x);
	int y_parent = find_parent(parent, y);

	if(x_parent != y_parent){

		if (rank[x_parent]>rank[y_parent])
			parent[y_parent] = x_parent;

		else if(rank[y_parent] > rank[x_parent])
			parent[x_parent] = y_parent;

		else{
			parent[y_parent] = x_parent;
			rank[x_parent]++;
		}
	}
	return 0;
}

int main()
{
	vi parent,rank;
	int nodes = 8;
	for(int i=0;i<nodes;i++){
		parent.push_back(i);
		rank.push_back(0);
	}

	find_union(parent,rank,0,1);
	find_union(parent,rank,2,3);
	find_union(parent,rank,4,5);
	find_union(parent,rank,5,0);
	find_union(parent,rank,2,1);
	find_union(parent, rank,7,6);
	

	
	for(int i=0;i<nodes;i++)
		cout<<"Parent of "<<i<<" is "<<parent[i]<<" "<<endl;
	
	return 0;
}
