#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n,m;
     cin>>n>>m;

        
        vector<vector<ll>>edges;



        for(int  i=0;i<m;i++){
            ll u,v,w;
            cin>>u>>v>>w;

            edges.push_back({u,v,w});
        }
        vector<ll>dis(n+1,0);
        vector<ll>parent(n+1,-1);

       


        int x=-1;

        for(int i=1;i<=n;i++){
            x=-1;

            for(int j=1;j<=m;j++){
            ll u=edges[j-1][0];
            ll v=edges[j-1][1];
            ll w=edges[j-1][2];

            if(dis[v]>dis[u]+w){
                x=v;
                dis[v]=dis[u]+w;
                parent[v]=u;
            }
        }   
        }
        // cout<<x<<endl;
        // cout<<parent[x]<<endl;


        if(x==-1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            
            // cout<<x<<endl;

            for(int j=0;j<n;j++){
                // cout<<"hi"<<endl;

                // cout<<x<<" ";
                x=parent[x];
                // cout<<x<<" ";
            }
            // cout<<endl;
            // cout<<x<<endl;

         

           ll curr=x;
           vector<ll>cycle;

           while(true){
            
                cycle.push_back(curr);
                curr=parent[curr];
                if(curr==x)break;
           }
           cycle.push_back(x);
           for(int i=cycle.size()-1;i>=0;i--){
                cout<<cycle[i]<<" ";

           }

        }

            



    return 0;
}