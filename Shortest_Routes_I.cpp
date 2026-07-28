#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>>adj(n+1);

    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});


    }

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

    pq.push({0,1});
    vector<long long>dis(n+1,1e18);
    dis[1]=0;
    dis[0]=0;

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
         
        int node=it.second;
        ll d=it.first;
        if(d!=dis[node])continue;

        for(auto itr:adj[node]){
            int vv=itr.first;
            ll w=itr.second;

            if(dis[vv]>(ll)d+(ll)w){
                dis[vv]=(ll)w+d;
                pq.push({dis[vv],vv});
            }

        }



    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;



  
    


}