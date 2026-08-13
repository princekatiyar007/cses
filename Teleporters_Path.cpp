#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int>ans;

void dfs(int node, vector<vector<int>>&adj){

    for(auto itr: adj[node]){
        // int v=adj[node].back();
        // adj[node].pop_back();
        dfs(itr,adj);
    }
    ans.push_back(node);
}

void isconnected(int node,vector<vector<int>>&adj, vector<int>&vis){
    vis[node]=true;
    for(auto itr:adj[node]){
        if(vis[itr]==0){
            isconnected(itr,adj,vis);
        }

    }
}

int main() {
     int n,m;
     cin>>n>>m;
     vector<vector<int>>adj(n+1);
     vector<int>indegree(n+1);
     vector<int>outdegree(n+1);


     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
        outdegree[u]++;
     }
     if(outdegree[1]-indegree[1]!=1 || indegree[n]-outdegree[n]!=1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
     }
     for(int i=2;i<n;i++){
        if(indegree[i]!=outdegree[i]){
            cout<<"IMPOSSIBLE"<<endl;
        return 0;

        }
     }
     vector<int>vis(n+1,0);
     isconnected(1,adj,vis);
      for(int i=1;i<=n;i++){
        if(vis[i]==0 && (indegree[i]!=0 || outdegree[i]!=0)){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;

        }
     }


     dfs(1,adj);
     for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
     }
    


    return 0;
}