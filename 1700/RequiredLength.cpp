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

map<int, int> ok;
int f(unsigned int x, unsigned int n) {
    if (ok.contains(x)) return ok[x];
    string s = to_string(x);
    if (s.size() == n) return ok[x] = 0;
    if (s.size() > n) return ok[x] = INT_MAX;

    int ans = INT_MAX;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '1' and s[i] != '0') {
            unsigned int y = s[i] - '0';
            unsigned int lim = ULLONG_MAX / x;
            if (y >= lim) return ok[x] = 1;
            else ans = min(ans, 1 + f(x * y, n));
        }
    return ok[x] = ans;
}

void solve() {
    unsigned int n, x; cin >> n >> x;
    int ans = f(x, n);
    cout << (ans == INT_MAX ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}