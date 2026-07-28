#include<bits/stdc++.h>
using namespace std;

vector<long long>depth;
void solve(int node , int par,int d, vector<vector<int>>&adj){



    depth[node]=d;

    for(auto itr:adj[node]){
        if(itr==par)continue;

        solve(itr,node,d+1,adj);


    }
    return;
}


int main(){
    long long n,q;
    cin>>n>>q;
    // if(n==1 ){
    //     cout<<n-1<<endl;
    //     return 0;
    // }
   
   
    long long rows=n+1;
    long long cols=log2(n+1)+1;

    vector<vector<long long>>par(rows,vector<long long>(cols,-1));
    vector<vector<int>>adj(n+1);


    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
       
        
        par[i][0]=x;
    }
    
    for(int j=1;j<cols;j++){
        for(int node=1;node<=n;node++){
            if(par[node][j-1]==-1)continue;

            par[node][j]=par[par[node][j-1]][j-1];

        }
    }
    depth.resize(n+1);

    solve(1,-1,0,adj);

    for(int i=0;i<q;i++){
        int u,v;


        cin>>u>>v;


        long long d1=depth[u];
        long long d2=depth[v];

        if(d2>d1){
            swap(u,v);
        }


        long long diff=abs(d1-d2);


        for(int j=0;j<cols;j++){

            
            
            if(diff & (1<<j)){
                u=par[u][j];
            }
        }
        if(u==v){
            cout<<u<<endl;
            continue;
        }
        
        int k=cols;

        while(k--)
        {
            if(par[u][k]!=par[v][k])
            {
                u=par[u][k];
                v=par[v][k];
            }
        }

        cout<<par[u][0]<<endl;

    }


  
    


}