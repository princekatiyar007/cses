#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod=1e9+7;

int main() {
     int n,m;
     cin>>n>>m;

     vector<vector<pair<int,int>>>adj(n+1);
     //u->(v,w);
     for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});

     }

     vector<ll>dis(n+1,1e18);
     vector<ll>ways(n+1,0);
     vector<int>minf(n+1,1e9);
     vector<int>maxf(n+1,-1e9);
     dis[1]=0;
     ways[1]=1;
     minf[1]=1;
     maxf[1]=1;

     priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;


     pq.push({0,1});

     while(!pq.empty()){
         auto it=pq.top();
         pq.pop();
         int u=it.second;
         ll d=it.first;
         if(d>dis[u])continue;

         for(auto itr:adj[u]){
            int v=itr.first;
            ll wt=itr.second;

            if(dis[v]>d+wt){
                dis[v]=dis[u]+wt;
                ways[v]=ways[u]%mod;
                minf[v]=minf[u]+1;
                maxf[v]=maxf[u]+1;
                pq.push({dis[v],v});

            }
            else if(dis[v]==d+wt){
                ways[v]=(ways[v]+ways[u])%mod;
                minf[v]=min(minf[u]+1,minf[v]);
                maxf[v]=max(maxf[v],maxf[u]+1);
                // pq.push({dis[v],v});
            }

         }
     }

     cout<<dis[n]<<" "<<ways[n] <<" "<<minf[n]-1<<" "<<maxf[n]-1<<endl;

    return 0;
}