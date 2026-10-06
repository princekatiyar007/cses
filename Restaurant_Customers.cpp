#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n;
     cin>>n;

     vector<pair<int,int>>v(n);
     for(int i=0;i<n;i++){
        
        cin>>v[i].first>>v[i].second;
     }

     sort(v.begin(),v.end());

     int ans=1;

     for(int i=0;i<n;i++){
        int start=v[i].first;
        int end=v[i].second;

        auto it=upper_bound(v.begin(),v.end(),make_pair(end,0))-v.begin();

        ans=max(ans,(int)(it-i));



     }
     cout<<ans<<endl;


    return 0;
}