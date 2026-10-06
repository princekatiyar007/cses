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
     vector<pair<int,int>>res;
     res.push_back(v[0]);

     for(int i=1;i<n;i++){
        int start=v[i].first;
        int end=v[i].second;

        
        if(start>=res.back().second){
            res.push_back(v[i]);
        }
        else{
            res.back().second=min(res.back().second,end);
        }

       


     }
     cout<<res.size()<<endl;


    return 0;
}