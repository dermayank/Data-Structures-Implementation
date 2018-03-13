#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
typedef vector<int> vi;
typedef vector< pair<int,p> > vii;

struct edges{
	int u,v,weight;
};

int add_edge(vii &adj, int u, int v, int weight){

	adj.push_back({weight,{u,v}});
}

int find_parent(vi &parent, int val){

	if(parent[val]!= val)
		parent[val] = find_parent(parent,parent[val]);

	return parent[val]; 
}

int find_union(vi &parent, vi &rank, vii &mst, int w, int x, int y){

	
	int x_parent = find_parent(parent,x);
	int y_parent = find_parent(parent,y);
	
	if(x_parent != y_parent){
			

		if(rank[x_parent] > rank[y_parent])
			parent[y_parent] = x_parent;

		else if(rank[y_parent] > rank[x_parent])
			parent[x_parent] = y_parent;

		else{
			parent[y_parent] = 	x_parent;
			rank[x_parent]++;
		}
		mst.push_back({w,{x,y}});
	}
	return 0;
}



int kruskal(vii &adj, vii &mst, vi &parent, vi &rank, int size){

	sort(adj.begin(), adj.end());
	vii::iterator it;

	for(it = adj.begin();it!= adj.end(); it++){
		find_union(parent, rank, mst, it->first,it->second.first,it->second.second);
	}
	return 0;
}


int main(){


	vi parent,rank;
	int nodes = 6;
	vii adj, mst;

	for(int i=0;i<nodes;i++){
		parent.push_back(i);
		rank.push_back(0);
	}

	add_edge(adj, 1,2,10);
	add_edge(adj, 2,3,4);
	add_edge(adj, 2,4,8);
	add_edge(adj, 1,5,7);
	add_edge(adj, 0,5,4);
	add_edge(adj, 0,4,1);
    add_edge(adj, 0,3,6);

    kruskal(adj, mst, parent, rank, nodes);

    vii::iterator it;
    for(it = mst.begin();it!= mst.end(); it++)
		cout<<it->second.first<<" "<<it->second.second<<" "<<it->first<<endl;


	return 0;
}
