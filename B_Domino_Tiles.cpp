#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;

int n;
string s;

long long dpres[200005][3][3];

long long solve(int i, int a, int b) {
    if (i == n) return 1;

    long long &ans = dpres[i][a][b];
    if (ans != -1) return ans;

    ans = 0;

    for (int j = 0; j <= 1; j++) {

        if (s[i] != '?' && s[i] != char(j + '0'))
            continue;

        if (i>= 2) {
            if (a == j) continue;
        }

        ans += solve(i + 1, b, j);
        ans %= MOD;
    }

    return ans;
}

int main() {

   

    int t;
    cin >> t;

    while (t--) {

        cin >> n;
        cin >> s;

        memset(dpres, -1, sizeof(dpres));

        cout << solve(0, 2, 2) << "\n";
    }
}