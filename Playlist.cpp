#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n;
     cin>>n;

     vector<int>nums(n);
     for(int i=0;i<n;i++){
        cin>>nums[i];
     }

     int start=0;
     int end=0;
     map<int,int>mp;
     
     int ans=0;
     while(end<n){

        
        mp[nums[end]]++;

        while(mp[nums[end]]>1 && start<=end && end<n){
            mp[nums[start]]--;
            start++;
        }
        ans=max(ans,end-start+1);
        end++;

     }
     cout<<ans<<endl;
    return 0;
}