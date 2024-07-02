#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

// O(n)
vector<int> z_function(string& s) {
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
            
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

v<int> z, dp;
int get(int n, int k, string& s) {
    int lo = 1, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (dp[mid] == -1) {
            int i = mid;
            dp[mid] = 1;
            while (i < n)
                if (z[i] >= mid)
                    i += mid, dp[mid]++;
                else
                    i++;
        }

        if (dp[mid] >= k)
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
    }

    return ans;
}

void solve() {
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;
    z = z_function(s);
    dp.assign(n + 1, -1);
    
    for (int i = l; i <= r; i++)
        cout << get(n, i, s) << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}