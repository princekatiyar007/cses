#include<bits/stdc++.h>
using namespace std;

long long cnt=0;
vector<vector<int>>dp;
int solve(int node,int par,int include,vector<vector<int>>&adj){

    if(dp[node][include]!=-1)return dp[node][include];

   
    int sum=0;



    for(auto child:adj[node]){
        if(child==par)continue;

        sum+= max(solve(child,node,0,adj),solve(child,node,1,adj));

        
    }

    if(include==0){
        return dp[node][0]=sum;
        
    }
    else{
        int maxi=0;
        for(auto child:adj[node]){

            if(child==par)continue;

            maxi=max(maxi,1+sum-max(solve(child,node,0,adj),solve(child,node,1,adj))+solve(child,node,0,adj));


        }
       return dp[node][1]=maxi;
    }

   
}

int main(){
    int n;
    cin>>n;

    if(n==1 || n==2){
        cout<<n-1<<endl;
        return 0;
    }
    
    
    vector<vector<int>>adj(n+1);

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
       
        adj[x].push_back(y);
        adj[y].push_back(x);

        
    }
    dp.resize(1e6,vector<int>(2,-1));
    
    solve(1,-1,0,adj);
    solve(1,-1,1,adj);

    cout<<max(dp[1][0],dp[1][1])<<endl;

   


}