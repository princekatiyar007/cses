#include<bits/stdc++.h>
using namespace std;


int main(){
    long long n,q;
    cin>>n>>q;
    if(n==1 ){
        cout<<n-1<<endl;
        return 0;
    }
   
   
    long long rows=n+1;
    long long cols=log2(n+1)+1;

    vector<vector<long long>>par(rows,vector<long long>(cols,-1));


    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
       
        
        par[i][0]=x;
    }
    par[1][0]=-1;

    for(int j=1;j<cols;j++){

        for(int node=2;node<=n;node++){
            if(par[node][j-1]==-1)continue;

            par[node][j]=par[par[node][j-1]][j-1];
        }

    }

    for(int i=0;i<q;i++){
        long long node,k;
        cin>>node>>k;

        for(int j=0;j<cols;j++){
            if(k & (1<<j)){
                if(par[node][j]==-1){
                    node=-1;
                    break;
                }
                node=par[node][j];
            }
        }
        cout<<node<<endl;
    }
    




  
    


}