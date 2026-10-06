#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>dp;
int m=1e9+7;


int solve(int s,int k){
    if(s==k)return 1;
    if(s>k)return 0;

    if(dp[s]!=-1)return dp[s];

    int cnt=0;
    for(int i=1;i<=6;i++){
        cnt =(cnt+solve(s+i,k))%m;

    }
    return dp[s]=cnt ;
}

int main() {

     int n;
     cin>>n;
     dp.resize(n,-1);

     cout<<solve(0,n);

     

    return 0;
}