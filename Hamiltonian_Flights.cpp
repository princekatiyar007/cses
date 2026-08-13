#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int nn;
ll mod=1e9+7;

ll dfs(int node,vector<vector<int>>&adj,set<int>&pathvis){
    pathvis.insert(node);
    // cout<<node<<endl;
    
    if(node==nn){
        if(pathvis.size()==nn){
            pathvis.erase(node);
            return 1;
        }
        pathvis.erase(node);
        return 0;

    }
    ll count=0;

    for(auto itr:adj[node]){
        if(pathvis.find(itr)==pathvis.end()){
            // cout<<node<<" "<<itr<<endl;
            count=(count+ dfs(itr,adj,pathvis))%mod;
        }
    }
    pathvis.erase(node);
    return count;
}

int main() {
     int n,m;
     cin>>n>>m;
     nn=n;

     vector<vector<int>>adj(n+1);
     
     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);

     }
     set<int>pathvis;
     cout<<dfs(1,adj,pathvis)<<endl;
     


    return 0;
}