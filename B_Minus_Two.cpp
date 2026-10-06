#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n;
     cin>>n;
     while(n--){
        int k;
        cin>>k;
        vector<int>v(k);
        int odd=0;
        int even_e=0;
        int even_o=0;
        int ans=1;
        for(int i=0;i<k;i++){
            cin>>v[i];
            if(v[i]%2!=0){
                odd++;
                ans=max(ans,odd);
            }
            else {
                int s=v[i]/2;

                if(s%2==0){
                    even_e++;
                   
                    ans=max(ans,even_e);
                }
                else{
                    even_o++;
                    ans=max(ans,even_o);
                }
            }
        }
        cout<<ans<<endl;
     }

    return 0;
}