#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 ll mod=1e9+7;


int main() {
     int n,m;
     cin>>n>>m;

     vector<vector<int>>adj(n+1);
     vector<ll>indegree(n+1,0);

     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
     }

    
     vector<ll>dis(n+1,0);
     vector<ll>flag(n+1,0);
     dis[1]=1;
     flag[1]=1;


     
     
     queue<ll>pq;
     
     for(int i=1;i<indegree.size();i++){
        if(indegree[i]==0){
            pq.push(i);
            // cout<<i<<endl;
        }
     }

        while(!pq.empty()){
            int node =pq.front();
            pq.pop();
            // cout<<node<<endl;

            for(auto v:adj[node]){
                indegree[v]--;
                // cout<<v<<endl;

                if(flag[node]==1){
                    flag[v]=1;
                    dis[v]=(dis[v]+dis[node])%mod;
                    // cout<<node<<" "<<v<<endl;
                }
                
               
                if(indegree[v]==0){
                    pq.push(v);
                }

           
            }
        }
        cout<<dis[n]<<endl;

     

 
}