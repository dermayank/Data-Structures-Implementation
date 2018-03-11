#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vi > vii;                    

int add_edge(vii &adj, int u, int v){

	adj[u].push_back(v);                
                    
	return 0;
}

int dfs_visit(vii &adj, int index, vi &visited){
	
	visited[index] = 1;
	cout<<"visited "<<index<<endl;

	vi::iterator it = adj[index].begin();
	for(;it!=adj[index].end();it++){
		if(visited[*it] == 0)
			dfs_visit(adj, *it, visited); 
	}

	return 0;
}

int dfs(vii &adj, int size){
	vi visited(size,0);

	for(int i=0; i<size; i++){
		if(visited[i] == 0)
			dfs_visit(adj, i, visited);  
	}
	return 0;
}

int main()
{
	int v = 7;						// vertex 0 to 6
	vii adj(v);
	
	add_edge(adj, 0,1);
	add_edge(adj, 1,2);
	add_edge(adj, 1,3);
	add_edge(adj, 2,6);
	add_edge(adj, 2,4);
	add_edge(adj, 2,3);
	add_edge(adj, 3,5);

	dfs(adj, v);

    return 0;
}
