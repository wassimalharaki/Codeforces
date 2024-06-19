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

v<int> bruteforce(v<int>& a, const int m) {
    int n = a.size();
    v<int> dp(1 << n);
    for (int i = 1; i < (1 << n); i++)
        dp[i] = (a[__lg(i)] + dp[i ^ (1 << __lg(i))]) % m;
    return dp;
}

void solve() {
    int n, m; cin >> n >> m;
    const int mod = m;

    v<int> a(n);
    for (int& x : a) cin >> x;

    if (n <= 18) {
        auto bf = bruteforce(a, m);
        cout << *max_element(bf.begin(), bf.end());
    }
    else {
        v<int> left, right;
        for (int i = 0; i < n / 2; i++)
            left.push_back(a[i]);
        for (int i = n / 2; i < n; i++)
            right.push_back(a[i]);
        
        auto left_bf = bruteforce(left, m);
        auto right_bf = bruteforce(right, m);
        sort(left_bf.begin(), left_bf.end());
        sort(right_bf.begin(), right_bf.end());
        
        int ans = 0;
        for (int& x : left_bf) {
            ans = max(ans, x);
            auto it = upper_bound(right_bf.begin(), right_bf.end(), mod - 1 - x);
            if (it != right_bf.begin())
                ans = max(ans, x + *(--it));
        }
        cout << ans;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}