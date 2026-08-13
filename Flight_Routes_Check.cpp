#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=true;
    for(auto itr:adj[node]){
        if(vis[itr]==0){
            dfs(itr,adj,vis);
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

     vector<int>vis(n+1,0);

     dfs(1,adj,vis);
     vector<int>vis1(n+1,0);
     dfs(1,rev,vis1);
     for(int i=1;i<=n;i++){
        if(vis[i]==0 ){
            cout<<"NO"<<endl;
            cout<<"1 "<<i<<endl;
            return 0;
        }
         if(vis1[i]==0 ){
            cout<<"NO"<<endl;
            cout<<i<<" 1"<<endl;
            return 0;
        }
     }
     cout<<"YES"<<endl;



    return 0;
}