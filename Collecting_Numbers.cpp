#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n;
     cin>>n;

     vector<int>v(n);
     map<int,int>mp;
     for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]=i;
     }

     int ans=0;
     int ind=1e9;

     for(int i=1;i<=n;i++){
        int ori_ind=mp[i];
        if(ind>ori_ind){
            ans++;


        }
        ind=ori_ind;

     }
     cout<<ans<<endl;

    return 0;
}