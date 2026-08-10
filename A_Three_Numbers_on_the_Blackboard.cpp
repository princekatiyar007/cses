#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int t;
     cin>>t;

     while(t--){
        int a,b,c;

        cin>>a>>b>>c;
        vector<int>v(3);
        v[0]=a;
        v[1]=b;
        v[2]=c;
        sort(v.begin(),v.end());
        v[2]=min(v[2],v[1]+v[0]);
        cout<<v[2]-v[0]<<endl;
        
     }

    return 0;
}