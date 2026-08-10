#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
     int n,m;
     cin>>n>>m;

     vector<vector<int>>adj(n+1);
     vector<int>indegree(n+1,0);

     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
     }

     vector<int>parent(n+1,0);
     vector<int>dis(n+1,-1e9);
     dis[1]=0;


     
     
     queue<int>pq;
     
     for(int i=1;i<indegree.size();i++){
        if(indegree[i]==0){
            pq.push(i);
        }
     }

        while(!pq.empty()){
            int node =pq.front();
            pq.pop();

            for(auto v:adj[node]){
                indegree[v]--;
                
                if(dis[node]+1>dis[v]){
                   
                    parent[v]=node;
                    dis[v]=dis[node]+1;
                    //  cout<<node <<" "<<v<<" "<<dis[node]<<" "<<dis[v]<<endl;
                }
                if(indegree[v]==0){
                    pq.push(v);
                }

           
            }
        }
        // cout<<dis[n]<<endl;

     if(dis[n]<0){
        cout<<"IMPOSSIBLE";
        return 0;
     }
     

     int u=n;
     vector<int>ans;

     while(u!=0){
        ans.push_back(u);
        u=parent[u];
     }
     cout<<ans.size()<<endl;
     for(int i=0;i<ans.size();i++){
        cout<<ans[ans.size()-1-i]<<" ";
     }





    return 0;
}