#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector< map<int, int> > vii;                    // replace map<int, int> with vector<int> for unweighted graph

int add_edge(vii &adj, int u, int v, int weight){

    adj[u].insert(make_pair(v,weight));
    adj[v].insert(make_pair(u,weight));                // remove this for directed graph

    return 0;
}

int dispaly_graph(vii &adj, int size)
{
	for(int i=0; i<size; i++){

		cout<<"Vertex "<<i<<" is connected to:"<<endl;
		map<int,int>::iterator it = adj[i].begin();
		
        for(;it!=adj[i].end();it++){
			cout<<"vertex "<<it->first<<" weight"<<it->second<<endl;
		}
		cout<<endl;
	}

	return 0;
}

int main()
{
	vii adj(6);
	
	add_edge(adj, 1,2,10);
	add_edge(adj, 2,3,4);
	add_edge(adj, 2,4,8);
	add_edge(adj, 1,5,7);
	add_edge(adj, 0,5,4);
	add_edge(adj, 0,4,1);
        add_edge(adj, 0,3,6);

	dispaly_graph(adj, 6);

    return 0;
}
