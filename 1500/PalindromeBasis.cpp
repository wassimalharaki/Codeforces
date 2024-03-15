#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

v<int> precomp;
v<int> dp(4e4 + 1);
const int mod = 1e9 + 7;

bool f(int n) {
    string s = to_string(n);
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - i - 1])
            return 0;
    return 1;
}

void solve() {
    int n; cin >> n;
    cout << dp[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 4e4; i++)
        if (f(i)) precomp.push_back(i);
    
    dp[0] = 1;
    for (int& a : precomp)
        for (int i = 0; i <= 4e4; i++)
            if (a + i <= 4e4)
                dp[a + i] = (dp[a + i] + dp[i]) % mod;

    int T = 1;
    cin >> T;
    while (T--) solve();
}