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

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    if (s == t) {
        cout << 0 << nl;
        return;
    }

    if (s.front() != t.front() or s.back() != t.back()) {
        cout << -1 << nl;
        return;
    }

    array<int, 2> a, b;
    a = b = {0, 0};
    a[s[0] - '0']++;
    b[s[0] - '0']++;
    
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1])
            a[s[i] - '0']++;
        if (t[i] != t[i - 1])
            b[t[i] - '0']++;
    }

    if (a != b) {
        cout << -1 << nl;
        return;
    }

    v<int> b_s{1}, b_t{1};
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            b_s.back()++;
        else
            b_s.push_back(1);
        if (t[i] == t[i - 1])
            b_t.back()++;
        else
            b_t.push_back(1);
    }

    int ans = 0;
    for (int i = 0; i < (int) b_s.size() - 1; i++) {
        b_s[i + 1] += b_s[i] - b_t[i];
        ans += abs(b_s[i] - b_t[i]);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}