#include<bits/stdc++.h>
using namespace std;
vector<int>sub_node;
int root_dis=0;
int n;
vector<int>ans;

    int find_subnodes(int node, int parent , int dep,vector<vector<int>>&adj){
        

        int subnodes=1;

        root_dis+=dep;

        for(auto itr:adj[node]){
            if(itr==parent)continue;

            subnodes+=find_subnodes(itr,node,dep+1,adj);
        }
        sub_node[node]=subnodes;
        return subnodes;
    }

    void solve(int node, int parent ,vector<vector<int>>&adj ){

        for(auto itr:adj[node]){
            if(itr==parent)continue;

            int x=ans[node];
            int childs=sub_node[itr];
            x=x-childs+(n-childs);
            ans[itr]=x;
            solve(itr,node,adj);
        }
    }
int main(){
    
    cin>>n;
    if(n==1 ){
        cout<<n-1<<endl;
        return 0;
    }
   
    vector<vector<int>>adj(n+1);

    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
       
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    
     
        sub_node.resize(n+1,0);
        
        ans.resize(n+1,0);
        find_subnodes(1,-1,0,adj);
        ans[1]=root_dis;
        solve(1,-1,adj);
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        return 0;



}