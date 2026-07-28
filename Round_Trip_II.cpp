#include<bits/stdc++.h>
using namespace std;

vector<int>ans;
int curr=-1;
vector<int>v;

bool dfs(int node,vector<vector<int>>&adj, vector<int>&vis,vector<int>&pathvis,vector<int>&parent){
    vis[node]=true;
    pathvis[node]=true;

    for(auto v:adj[node]){

        if(vis[v]==false){

            parent[v]=node;

             if(dfs(v,adj,vis,pathvis,parent))return true;
        }
        else if(pathvis[v]==true){
             parent[v]=node;
              if(curr==-1){
                 curr=v;
            
            }
           
           
            return true;
        }
        
         
        
          
           
            
        }
    
    pathvis[node]=false;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }
    
    vector<int>vis(n+1,0);
    vector<int>pathvis(n+1,0);
    vector<int>parent(n+1,0);

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(i,adj,vis,pathvis,parent))break;
        }
    }
    // cout<<v.size()<<endl;
    if(curr==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{

             
             
            int temp=curr;
            while(true){
                ans.push_back(curr);
                curr=parent[curr];
                if(curr==temp)break;

            }
            ans.push_back(curr);
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";

        }
    }

}