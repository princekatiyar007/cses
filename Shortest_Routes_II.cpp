#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// vector<ll> find(int nod, vector<vector<pair<int,int>>>&adj){

//     int n=adj.size();

//     priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

//     pq.push({0,nod});
//     vector<long long>dis(n+1,1e18);
//     dis[nod]=0;
//     // dis[0]=0;

//     while(!pq.empty()){
//         auto it=pq.top();
//         pq.pop();
         
//         int node=it.second;
//         ll d=it.first;
//         if(d!=dis[node])continue;

//         for(auto itr:adj[node]){
//             int vv=itr.first;
//             ll w=itr.second;

//             if(dis[vv]>(ll)d+(ll)w){
//                 dis[vv]=(ll)w+d;
//                 pq.push({dis[vv],vv});
//             }

//         }



//     }
//     return dis;

// }


int main(){
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll>>dis(n+1,vector<ll>(n+1,1e18));


    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
       
        dis[u][v]=min(w,dis[u][v]);
        dis[v][u]=min(w,dis[v][u]);


        for(int i=1;i<=n;i++){
            dis[i][i]=0;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;

                if(dis[i][j]>(ll)dis[i][k]+dis[k][j]){
                    dis[i][j]=(ll)dis[i][k]+dis[k][j];
                }
            }
        }
    }
    
    
    
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        if(dis[u][v]==1e18){
            cout<<-1<<endl;
            continue;
        }
        cout<<dis[u][v]<<endl;

    }
    return 0;



  
    


}