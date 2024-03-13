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

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int f(int x) {
    int ans = 0;
    string s = to_string(x);
    for (char& c : s) ans += c - '0';
    return ans;
}

void solve() {
    int a, b, c; cin >> a >> b >> c;

    v<int> ans;
    for (int i = 0; i <= 100; i++) {
        int x = binpow(i, a) * b + c;
        if (i == f(x) and x > 0 and x < 1e9)
            ans.push_back(x);
    }
    sort(all(ans));

    cout << ans.size() << nl;
    for (int& a : ans) cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}