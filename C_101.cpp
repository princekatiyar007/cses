#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int t;
     cin>>t;

     while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int start=-1;
        
        for(int i=0;i<n;i++){
            if(v[i]==1){
                start=i;
                break;
            }
            else if(v[i]==-1){
                start=i;
                v[i]=1;
                break;
            }
        }
        int end=n;

        for(int i=n-1;i>start;i--){
            if(v[i]==1){
                end=i;
                break;
            }
            else if(v[i]==-1){
                end=i;
                v[i]=1;
                break;
            }
        }
        for(int i=start;i<end;i++){
            if(v[i]==-1){
                v[i]=0;
            }
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
     }

    return 0;
}