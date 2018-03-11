#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int cycle = 0;

int add_edge(vii &adj, int u, int v){
	adj[u].push_back(v);
}

int dfs_visit(vii &adj, int index, vi &visited){

	if(cycle == 0 && visited[index]==0){
		visited[index] = 1;

		vi::iterator it = adj[index].begin();
		for(;it!=adj[index].end(); it++){
			if(visited[*it]==0)	
				dfs_visit(adj, *it, visited);
			else
				cycle = 1;	
		}
	}
	return 0;
}

int dfs(vii &adj, int size){

	vi visited(size,0);

	for(int i=0; i<size; i++)
		dfs_visit(adj, i, visited);

	return 0;
}

int main()
{
	int v = 7;						// vertex 0 to 6
	vii adj(v);
	
	add_edge(adj, 0,1);
	add_edge(adj, 1,2);
	add_edge(adj, 2,3);
	add_edge(adj, 5,6);
	add_edge(adj, 2,4);
	add_edge(adj, 4,5);

	dfs(adj, v);

	if(cycle == 0)
		cout<<"no cycle found"<<endl;
	else
		cout<<"cycle exit"<<endl;

    return 0;
}
