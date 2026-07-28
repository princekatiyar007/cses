#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,int>>>adj(n+1);

    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }

    vector<vector<ll>>dis(n+1);

    // dis[1].push_back(0);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll   >>>pq;
    pq.push({0,1});

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        ll d=it.first;
        ll node=it.second;

        if(dis[node].size()==k)continue;

        

        dis[node].push_back(d);

        for(auto itr:adj[node]){
            int v=itr.first;
            ll wt=itr.second;

             pq.push({d+wt,v});
        }
    }
    for(int i=0;i<k;i++){
       
            cout<<dis[n][i]<<" ";
       
    }
    
}
