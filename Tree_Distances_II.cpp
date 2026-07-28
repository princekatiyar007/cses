#include<bits/stdc++.h>
using namespace std;

    long long sum=0;
    vector<long long>cnt;
    vector<long long>ans;
    int n;
    long long solve(int node, int par, long long depth, vector<vector<int>>&adj){
    sum+=depth;

    long long total=1;

    for(auto child:adj[node]){
        if(child==par)continue;

        total+=solve(child,node,depth+1,adj);
    }
    cnt[node]=total;
    return total; 


    }

    void found(int node, int parent,  vector<vector<int>>&adj){

        for(auto child:adj[node]){
            if(child==parent)continue;

            ans[child]=ans[node]-cnt[child]+n-cnt[child];
            found(child,node,adj);


        }
    }

int main(){
    
    cin>>n;
    if(n==1 ){
        cout<<n-1<<endl;
        return 0;
    }
   
    vector<vector<int>>adj(n+1);

    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
       
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    
     
        cnt.resize(n,0);
        solve(0,-1,0,adj);
        ans.resize(n,0);
        ans[0]=sum;
        found(0,-1,adj);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        return 0;



}