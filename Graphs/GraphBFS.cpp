

// class solution
// {
// public:
//     vector<int> bfsOfGraph(int V, vector<int> adg[])
//     {
//         int vis[n] = {0};
//         vis[0] = 1;
//         queue<int> q;
//         q.push(0);
//         vector<int> bfs;
//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();
//             bfs.push(node);

//             for (auto it : adj[node])
//             {
//                 if (!vis[it])
//                 {
//                     vis[it] = 1;
//                     q.push(it);
//                 }
//             }
//         }
//     return bfs;
//     }
// }



#include <bits/stdc++.h>
using namespace std;

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

     int vis[n] = {0};
      vis[0] = 1;

    queue<int> q;
    q.push(0);

    vector<int> bfs; 
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;

                q.push(it);
            }
        }
    }

      for (int node : bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}