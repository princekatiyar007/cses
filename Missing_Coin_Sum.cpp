#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n;
     cin>>n;
     vector<int>v(n,0);
     for(int i=0;i<n;i++){
        cin>>v[i];
     }
     sort(v.begin(),v.end());
     long long ans=-1;
     long long sum=0;

     for(int i=0;i<n;i++){
        if(v[i]>sum+1){
            ans=sum+1;
            break;
        }
        else{
            sum+=(long long)v[i];
        }
     }
     if(ans==-1){
        cout<<sum+1<<endl;
     }
     else{
        cout<<ans<<endl;
     }

    return 0;
}