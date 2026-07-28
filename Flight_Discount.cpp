#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n,m;
     cin>>n>>m;

     vector<vector<pair<ll,ll>>>adj(n+1);

     for(int  i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
     }

     priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;

     pq.push({0,1,0});
     vector<vector<ll>>dis(n+1,vector<ll>(2,1e18));
     map<pair<ll,ll>,ll>mp;
     //node,maxi->dis
     dis[1][0]=0;
     dis[1][1]=0;
     mp[{1,0}]=0;

     while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        ll d=it[0];
        ll node=it[1];
        ll used=it[2];

        if(d>dis[node][used])continue;

        for(auto itr:adj[node]){
            ll v=itr.first;
            ll wt=itr.second;

            if(used==true){
                if(dis[v][1]>d+wt){
                    dis[v][1]=d+wt;
                    pq.push({dis[v][1],v,1});
                }

            }
            else{
                if(dis[v][0]>d+wt){
                    dis[v][0]=d+wt;
                    pq.push({dis[v][0],v,0});
                }

                if(dis[v][1]>d+(wt/2)){
                    dis[v][1]=d+(wt/2);
                    pq.push({dis[v][1],v,1});
                }
            }

            // if(wt>maxi){
            //     ll x=d-(maxi/2)+maxi+(wt/2);
            //     if(dis[v]>x){
            //         dis[v]=x;
            //         pq.push({dis[v],v,wt});
            //     }

            // }
            // else{
            //     if(dis[v]>d+wt){
            //         dis[v]=d+wt;
            //         pq.push({dis[v],v,maxi});
            //     }

            // }
          

           
        }
       
     }
     

 

      cout<< dis[n][1]<<endl;

    return 0;
}