#include<bits/stdc++.h>
using namespace std;

vector<long long>depth;
void solve(int node , int par,int d, vector<vector<int>>&adj,vector<vector<int>>&parent){



    depth[node]=d;

    for(auto itr:adj[node]){
        if(itr==par)continue;

        parent[itr][0]=node;
        solve(itr,node,d+1,adj,parent);


    }
    return;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long n,q;
    cin>>n>>q;
    // if(n==1 ){
    //     cout<<n-1<<endl;
    //     return 0;
    // }
   
   
    long long rows=n+1;
    long long cols=20;

    vector<vector<int>>par(rows,vector<int>(cols,-1));
    vector<vector<int>>adj(n+1);


    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
       
        
        // par[i][0]=x;
    }
     depth.resize(n+1);
      solve(1,-1,0,adj,par);
    for(int j=1;j<cols;j++){
        for(int node=1;node<=n;node++){
            if(par[node][j-1]==-1)continue;

            par[node][j]=par[par[node][j-1]][j-1];

        }
    }
   

  

    for(int i=0;i<q;i++){
        int u,v;
        


        cin>>u>>v;
        int a=u;
        int b=v;


        long long d1=depth[u];
        long long d2=depth[v];

        if(d2>d1){
            swap(u,v);
        }

        long long ans=0;



        long long diff=abs(d1-d2);
        


        for(int j=0;j<cols;j++){          
            if(diff & (1<<j)){
                u=par[u][j];
            }
        }

        
        if(u==v){
            cout<<diff<<endl;
            continue;
        }
        
        int k=cols;

        while(k--)
        {
            if(par[u][k]!=par[v][k] && par[u][k]!=-1)
            {
                
                u=par[u][k];
                v=par[v][k];
            }
        }
        int up=par[u][0];
        // cout<<depth[u]<<" "<<depth[v]<<" "<<depth[up]<<endl;
        ans=(depth[a]- depth[up]) +( depth[b]-depth[up]);

        cout<<ans<<endl;

    }


  
    


}