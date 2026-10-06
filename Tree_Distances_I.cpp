#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>maxdis1;
vector<ll>maxdis2;
vector<ll>maxchild;
vector<ll>ans;



ll finddis(int node, int parent, vector<vector<int>>&adj){
    

    for(auto itr:adj[node]){
        if(itr==parent)continue;


        ll x=finddis(itr,node,adj)+1;
        if(x>maxdis1[node]){
            maxdis2[node]=maxdis1[node];
            maxdis1[node]=x;
            maxchild[node]=itr;
        }
        else if(x>maxdis2[node]){
            maxdis2[node]=x;
        }

    }
    return maxdis1[node];
}

void solve(int node, int parent, ll from_par,vector<vector<int>>&adj){

    for(auto itr:adj[node]){
        if(itr==parent)continue;

        ll childdis=maxdis1[itr];

        ll par_dis=from_par;

        if(itr == maxchild[node]){
            par_dis=max(par_dis,maxdis2[node]);
        }
        else{
            par_dis=max(par_dis,maxdis1[node]);
        }
        par_dis++;
        ans[itr]=max(par_dis,childdis);
        solve(itr,node,par_dis,adj);
    }
}

int main() {
     int n;
     cin>>n;

     vector<vector<int>>adj(n+1);
     for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

     }
     maxdis1.resize(n+1,0);
     maxdis2.resize(n+1,0);
     maxchild.resize(n+1,0);
     ans.resize(n+1,0);

     int init_dis=finddis(1,-1,adj);
     ans[1]=init_dis;

     solve(1,-1,0,adj);
     for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
     }


     
     

    return 0;
}