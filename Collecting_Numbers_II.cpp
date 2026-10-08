#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n,m;
     cin>>n>>m;

     vector<int>nums(n);
     vector<int>pos(n+2);
     for(int i=0;i<n;i++){
        cin>>nums[i];
        pos[nums[i]]=i;
     }
     pos[0]=-1;
     pos[n+1]=n;

     int ans=1;

     for(int i=1;i<=n;i++){
        int pos_x=pos[i];
        int pos_y=pos[i+1];
        if(pos_y<pos_x){
            ans++;
        }

     }
     

     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;

        if(u>v){
            swap(u,v);
        }
       

        int x=nums[u];
        int y=nums[v];
        int a=x;
        int b=y;

        if(x==y+1 || x==y-1){
            if(x>y)
            {ans--;}
            else{ ans++;}
        }

        // if(x>y){
        //     swap(x,y);
        //     // swap(u,v);
        // }

        if(pos[x+1]>u && pos[x+1]<v)ans++;
        if(pos[x-1]>u && pos[x-1]<v)ans--;
        if(pos[y-1]>u && pos[y-1]<v)ans++;
        if(pos[y+1]>u && pos[y+1]<v)ans--;

        pos[x]=v;

        pos[y]=u;
        nums[u]=y;
        nums[v]=x;

        






        cout<<ans<<endl;

     }




    return 0;
}