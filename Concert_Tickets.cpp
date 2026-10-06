#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n,m;
     cin>>n>>m;

     vector<int>ticket(n);
     vector<int>price(m);
     multiset<int>st;
     for(int i=0;i<n;i++){
        cin>>ticket[i];
        st.insert(ticket[i]);
     }
     for(int i=0;i<m;i++){
        cin>>price[i];
        int x=price[i];

        auto ind=st.upper_bound(x);
       
         if(ind==st.begin()){
            cout<<-1<<endl;


        }
        else{
            ind--;
            cout<<*ind<<endl;
            st.erase(ind);

        }

     }
   

     
     
    //  for(auto it:st){
    //     cout<<it<<endl;
    //  }

    

    return 0;
}