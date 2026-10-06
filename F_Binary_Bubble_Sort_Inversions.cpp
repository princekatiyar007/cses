#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) {
            cin >> x;
        }

        string s;
        cin >> s;

        /*
            x[i] = number of zeros to the right of the i-th 1.

            We only store positive x[i]'s.
        */

        deque<long long> dq;

        long long zeros = 0;
        long long inversions = 0;

        // Build x[] from right to left.
        vector<long long> x;

        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == 0) {
                ++zeros;
            } else {
                x.push_back(zeros);
                inversions += zeros;
            }
        }

        reverse(x.begin(), x.end());

        // Only positive values are useful.
        for (long long v : x) {
            if (v > 0) {
                dq.push_back(v);
            }
        }

        /*
            lazy = how much should be subtracted from
            every value currently in dq.
        */
        long long lazy = 0;

        cout << inversions << ' ';

        for (char c : s) {

            if (c == '0') {
                /*
                    Reverse bubble.

                    Every positive x decreases by 1.

                    If there are k positive elements,
                    inversion count decreases by k.
                */

                long long cnt = dq.size();

                inversions -= cnt;

                ++lazy;

                /*
                    Values at the back may have become zero.

                    Since x is non-increasing, all zero values
                    will appear at the back.
                */
                while (!dq.empty() && dq.back() - lazy == 0) {
                    dq.pop_back();
                }

            } else {
                /*
                    Normal bubble.

                    x transforms like:

                    [x1, x2, x3, ..., xk]
                       ->
                    [x2, x3, ..., xk, 0]

                    Therefore we remove x1.

                    Actual value of the front element is:
                    dq.front() - lazy
                */

                if (!dq.empty()) {
                    long long value = dq.front() - lazy;

                    inversions -= value;

                    dq.pop_front();
                }
            }

            cout << inversions << ' ';
        }

        cout << '\n';
    }

    return 0;
}