#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<int,int>mp;

void dfs(int node, vector<vector<int>>&adj,vector<int>&topo,vector<int>&vis ){
    vis[node]=true;

    for(auto itr:adj[node]){
        if(vis[itr]==false){
            dfs(itr,adj,topo,vis);
        }
    }
    topo.push_back(node);
}

void dfs1(int node, vector<vector<int>>&adj,vector<int>&vis1,int count){
    vis1[node]=true;
    mp[node]=count;
    for(auto itr:adj[node]){
        if(vis1[itr]==false){
            dfs1(itr,adj,vis1,count);
        }
    }


}

int main() {
     int n,m;
     cin>>n>>m;

     vector<vector<int>>adj(n+1);
     vector<vector<int>>rev(n+1);

     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);
     }
     vector<int>topo;
     vector<int>vis(n+1);
     for(int i=1;i<=n;i++){
        if(vis[i]==0){
            
            dfs(i,adj,topo,vis);
        }
     }
     vector<int>vis1(n+1,0);
     int count=0;
     for(int i=topo.size()-1;i>=0;i--){
        int node=topo[i];
        if(vis1[node]==0){
            count++;
            dfs1(node,rev,vis1,count);
        }
        

     }
     cout<<count<<endl;
     for(int i=1;i<=n;i++){
        
        cout<<mp[i]<<" ";
     }

    return 0;
}