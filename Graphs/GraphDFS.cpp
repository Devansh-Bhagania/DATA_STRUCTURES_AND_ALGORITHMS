


// class Solution {
//     private:
//     void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
//         vis[node] = 1;
//         ls.push_back(node);

//         for(auto it: adj[node]){
//             if(!vis[it]){
//                 dfs(it,adj,vis,ls);
//             }
//         }
//     }



//     public:
//     vector<int> dfsOfGraph(int V, vector<int> adj[]){
//         int vis[n] = {0};

//         int start = 0;
//         vector<int> ls;
//         dfs(start, adj, vis , ls);
//         return ls;
//     }
// }


#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector <int> &ls){
    vis[node] =1;
    ls.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}

int main (){
       int n,m;
     cin >> n >> m;

     vector<int> adj[n+1];

     for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
     }

     vector<int> ls;
     int vis[n+1] = {0};
        
     dfs(0,adj,vis,ls);


        for(auto it: ls){
            cout<<it << ' '; 
        }


     return 0;
}
