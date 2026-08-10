#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int>parent;
vector<int>sizee;

int findpar(int u){
    if(parent[u]==u)return u;
    return findpar(parent[u]);
}

void unionbysize(int u,int v){
    int upu=findpar(u);
    int upv=findpar(v);
    if(upu==upv)return;

    if(sizee[upu]>sizee[upv]){
        sizee[upu]+=sizee[upv];
        parent[upv]=parent[upu];
    }
    else{
        sizee[upv]+=sizee[upu];
        parent[upu]=parent[upv];

    }
}

int main() {
     int n,m;
     cin>>n>>m;

     vector<vector<int>>adj(m);

     for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[i]={c,a,b};
     }
     sort(adj.begin(),adj.end());
     parent.resize(n+1);
     for(int i=1;i<=n;i++)parent[i]=i;
     sizee.resize(n+1,1);
     ll ans=0;

     for(int i=0;i<m;i++){

        int u=adj[i][1];
        int v=adj[i][2];
        int w=adj[i][0];

        if(findpar(u)==findpar(v))continue;

        ans+=w;
        unionbysize(u,v);

     }
     int p=findpar(1);

     for(int i=1;i<=n;i++){
        if(findpar(i)!=p){
            cout<<"IMPOSSIBLE";
            return 0;
        }

     }
     cout<<ans<<endl;



    return 0;
}