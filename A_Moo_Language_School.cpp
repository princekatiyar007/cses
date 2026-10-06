#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n;
     cin>>n;
     while(n--){
        int m ,k;
        cin>>m>>k;
        string s;
        cin>>s;

        int i=0;
        int count=0;
        while(i<s.size()){
            bool flag=0;

          
            int c=k;
            while(c--){
                // cout<<s[i]<<endl;
                if(s[i]=='0'){
                    flag=1;

                    
                    
                }
                i++;



            }
            if(flag==0){
                count++;
            }
            // cout<<"count "<<count<<endl;
            
        }
        cout<<count<<endl;


     }

    return 0;
}