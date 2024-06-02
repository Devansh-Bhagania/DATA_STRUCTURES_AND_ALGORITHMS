

// the graph representation in list it is done with vector 

#include<iostream>
using namespace std;

int main (){
    int n , m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i=0;i<m:i++){
        int u,v;
        cin u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);   if directed graph is there no opposite connection 
    }
    return 0;
}