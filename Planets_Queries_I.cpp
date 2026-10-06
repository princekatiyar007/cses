#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
     int n,m;
     cin>>n>>m;
     vector<int>parent(n+1);
     for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        parent[i]=u;
     }

     vector<vector<int>>anc(30,vector<int>(n+1));

    return 0;
}