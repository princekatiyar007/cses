#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>&rev,vector<int>&dp){


    for(auto itr:rev[node]){
        int v=itr;
        if(  dp[v]==-1 ) {
        dp[v]=dp[node]+1;
        dfs(v,rev,dp);

    }


    }


   
    


    
   
    
   
   

    
   

    

}

int main() {
     int n;
     cin>>n;

     vector<int>next(n+1);
     vector<vector<int>>rev(n+1);
     vector<int>indegree(n+1,0);
     
     for(int i=1;i<=n;i++){
        cin>>next[i];
        indegree[next[i]]++;
        rev[next[i]].push_back(i);
     }

     queue<int>q;
     vector<int>incycle(n+1,1);
     for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
     }

     while(!q.empty()){
        auto node=q.front();
        q.pop();

        incycle[node]=0;

        int v=next[node];
        indegree[v]--;
        if(indegree[v]==0){
            q.push(v);
        }

     }
        vector<int>vis(n+1,0);
        vector<int>dp(n+1,-1);

     for(int i=1;i<=n;i++){
        if(incycle[i]==1 && vis[i]==0){
            
            int curr=i;
            vis[i]=1;
            int start=curr;
            curr=next[curr];
            int len=1;
            while(curr!=start){
                vis[curr]=1;
                len++;
                curr=next[curr];
            }
            curr=i;
            start=curr;
            dp[start]=len;
            curr=next[curr];
            while(curr!=start){
                dp[curr]=len;
                curr=next[curr];
            }

        }
     }
   
     for(int i=1;i<=n;i++){
        if(incycle[i]==1  ){

            // cout<<i<<endl;
            dfs(i,rev,dp);
        }
     }

     for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
     }
     




    return 0;
}