#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int ans=1;
int solve(int node,int par,  vector<vector<int>>&adj){

    int x=0;
    int max1=0;
    int max2=0;
    for(auto child:adj[node]){
        if(child==par)continue;

        int x=solve(child,node,adj);
        if(x>max1){
            max2=max1;
            max1=x;
        }
        else if(x>max2){
            max2=x;
        }
    }
    ans=max(ans,max1+max2);

    return max1+1;

    
}

int main(){
    int n;
    cin>>n;
    if(n==1 || n==2){
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

    // dp.resize(n,-1);
    solve(1,-1,adj);

    // for(int i=0;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }
    cout<<ans<<endl;
    return 0;


}