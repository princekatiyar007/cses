#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int>v;

void dfs(int node,  vector<set<int>>&adj){
    
    
    while(adj[node].size()!=0){
        int v=*adj[node].begin();
        adj[node].erase(v);
        adj[v].erase(node);
        dfs(v,adj);

    }
    // cout<<node<<endl;
    v.push_back(node);
}

void isconnected(int node, vector<set<int>>&adj,vector<int>&vis){
    vis[node]=true;
    for(auto v:adj[node]){
        if(vis[v]==0){
            isconnected(v,adj,vis);
        }
    }
}
int main() {
     int n,m;
     cin>>n>>m;

     vector<set<int>>adj(n+1);
     vector<int>indegree(n+1);

     for(int i= 0;i<m;i++){

        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        indegree[u]++;
        indegree[v]++;


     }
     for(int i=1;i<=n;i++){
        if((indegree[i]%2)!=0){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
     }
     vector<int>vis(n+1,0);
     isconnected(1,adj,vis);
     for(int i=1;i<=n;i++){
        if(vis[i]==0 && indegree[i]!=0){

            // cout<<i<<endl;
             cout<<"IMPOSSIBLE"<<endl;
            return 0;

        }
     }

    
     dfs(1, adj);
     reverse(v.begin(),v.end());
     for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
     }

    return 0;
}