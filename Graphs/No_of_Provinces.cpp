#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int> adj[], int vis[]){
    vis[node] =1;
     for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
     }
}

int main(){
    int n,m;
     cin >> n >> m;

     vector<int> adj[n+1];

     for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
     }

    int vis[n+1] = {0};
    int cnt = 0;
    for(int i=0;i< n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adj,vis);
        }
    }
    cout << cnt;

}