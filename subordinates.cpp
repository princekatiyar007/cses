#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int solve(int node,  vector<vector<int>>&adj){

    int x=0;
    for(auto child:adj[node]){
        x+=1+solve(child,adj);

    }
    return dp[node-1]=x;
}

int main(){
    int n;
    cin>>n;
    vector<int>parent(n+1,-1);
    parent[1]=1;
    vector<vector<int>>adj(n+1);

    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        parent[i]=x;
        adj[x].push_back(i);
    }

    dp.resize(n,-1);
    solve(1,adj);

    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return 0;


}