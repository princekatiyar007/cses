#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        int found = -1;
        for (int i = 0; i < 1e9; i++)
        {
            if (mp[i] < 3)
            {
                found = i;
                break;
            }
        }
        // cout<<found<<endl;
        int mex1, mex2, mex3;

        int cnt = mp[found];
        if (cnt == 0)
        {
            mex1 = found;
            mex2 = found;
            mex3 = found;
        }
        else if (cnt == 1)
        {
            mex1 = found + 1;
            mex2 = found;
            mex3 = found;
        }
        else
        {
            mex1 = found + 1;
            mex2 = found + 1;
            mex3 = found;
        }
        // cout<<mex1<<" "<<mex2<<" "<<mex3<<endl;

        if (mex1 + mex2 + mex3 < 2*max({mex1, mex2, mex3}))
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        set<int> as, bs;

        vector<char>ans(n);
        for (int i = 0; i < n; i++)
        {
            int a = v[i];

            if (a > found)
            {
                // cout<<"1  ";
                ans[i] = 'C';
            }
            else if (a < found)
            {
                //  cout<<"2  ";
                if (as.find(a) == as.end())
                {
                    ans[i] = 'A';
                    as.insert(a);
                }
                else if (bs.find(a) == bs.end())
                {
                    ans[i] = 'B';
                    bs.insert(a);
                }
                else
                {
                    ans[i] = 'C';
                }
            }
            else
            {
                // cout<<"3  ";

                if (cnt == 1)
                {
                    ans[i] = 'A';
                }
                else
                {
                     if (as.find(a) == as.end())
                {
                    ans[i] = 'A';
                    as.insert(a);
                }
                else if (bs.find(a) == bs.end())
                {
                    ans[i] = 'B';
                    bs.insert(a);
                }
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i];
        }
        cout<<endl;
    }

    return 0;
}