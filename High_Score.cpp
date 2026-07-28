#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n,m;
     cin>>n>>m;

     vector<vector<ll>>vec(m);
     vector<vector<pair<ll,ll>>>adj(n+1);
     for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        vec[i-1]={u,v,w};
        adj[u].push_back({v,w});
     }

     vector<ll>dis(n+1,-1e18);
     dis[1]=0;
    //  cout<<n<<endl;

     for(int i=0;i<n-1;i++){

        for(int j=0;j<m;j++){
            int u=vec[j][0];
            int v=vec[j][1];
            ll w=vec[j][2];
            if(dis[u]==-1e18)continue;

            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
            }

            // cout<<u <<" "<<v<<" "<<dis[v]<<endl;

        }
        // cout<<endl;
        

     }
     vector<ll>v=dis;
     bool flag=false;
     set<int>cyc;
     for(int j=0;j<m;j++){
            int u=vec[j][0];
            int v=vec[j][1];
            int w=vec[j][2];

            if(dis[u]==-1e18)continue;

            // if(dis[v]<dis[u]+w && v==n){
            //    flag=true;
            //    break;
            // }
             if(dis[v]<dis[u]+w){
                // dis[v]=dis[u]+w;
                cyc.insert(v);
                // cout<<v<<endl;
            }


    }
    queue<int>q;
    q.push(1);

    vector<int>vis(n+1,0);
    vector<int>vis2(n+1,0);
    queue<int>q2;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=true;


        if(cyc.find(u)!=cyc.end()){
            q2.push(u);
            // cout<<"sec  "<<u<<endl;
            
        }
        for(auto it:adj[u]){
            int v=it.first;
            ll w=it.second;
            if(vis[v]==0){
                q.push(v);
                vis[v]=true;
            }
        }

    }

    while(!q2.empty()){
        int u=q2.front();
        q2.pop();
        vis2[u]=true;
        // cout<<"u: "<<u<<endl;


        if(u==n){
            flag=true;
            break;
            
        }
        for(auto it:adj[u]){
            ll v=it.first;
            ll w=it.second;
            if(vis2[v]==0){
                q2.push(v);
                vis2[v]=true;
            }

        }


    }
    // cout<<flag<<endl;













    // cout<<flag<<endl;
    if(flag){
        cout<<-1<<endl;
    }
    else{

        cout<<dis[n]<<endl;
    }


    return 0;
}