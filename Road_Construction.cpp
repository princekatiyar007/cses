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

    
     parent.resize(n+1);
     for(int i=1;i<=n;i++)parent[i]=i;
     sizee.resize(n+1,1);
     int com=n;
     int maxi=1;

     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
       

        
       if(findpar(u)==findpar(v)){
        cout<<com<<" "<<maxi<<endl;
       }
       else{

            unionbysize(u,v);
            int upu=findpar(u);
            int upv=findpar(v);

            maxi=max({maxi,sizee[upu],sizee[upv]});
            com=com-1;
            cout<<com<<" "<<maxi<<endl;


            
       }


        
     }
     
     

    return 0;
}