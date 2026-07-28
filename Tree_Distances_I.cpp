#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int ans=1;
vector<int>max1;
vector<int>max2;
int solve(int node,int par,  vector<vector<int>>&adj){

    int x=0;
    
    for(auto child:adj[node]){
        if(child==par)continue;

        int x=solve(child,node,adj);
        if(x>max1[node]){
            max2[node]=max1[node];
            max1[node]=x;
        }
        else if(x>max2[node]){
            max2[node]=x;
        }
    }
    

    return max1[node]+1;

    
}

void find(int node, int par, int parsum, vector<vector<int>>&adj ){


    for(auto child:adj[node]){
        int ans=0;

        if(child==par)continue;

      
        ans=max(ans,parsum+1);
        int x=max1[node];

        if(x==max1[child]+1){
            ans=max(ans,max2[node]+1);
        }
        else{
            ans=max(ans,max1[node]+1);
        }
        find(child,node,ans,adj);
        ans=max(ans,max1[child]);
        dp[child]=ans;

        
    }
}

int main(){
    int n;
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

    max1.resize(n+1,0);
    max2.resize(n+1,0);
    dp.resize(n+1,0);
    solve(1,-1,adj);
    find(1,-1,0,adj);
    dp[1]=max1[1];

    // for(int i=1;i<n+1;i++){
    //     cout<<max1[i]<<" "<<max2[i]<<endl;
    // }
    // cout<<ans<<endl;
    for(int i=1;i<n+1;i++){
        cout<<dp[i]<<" ";
    }
    return 0;


}