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
    int n, m; cin >> n >> m;
    string s; cin >> s;

    //rightmost 1, leftmost 0
    v<int> rm1(n), lm0(n);
    int curr = n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') curr = i;
        rm1[i] = curr;
    }
    curr = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') curr = i;
        lm0[i] = curr;
    }

    set<array<int, 2>> have;
    while (m--) {
        int l, r; cin >> l >> r;
        l = rm1[l - 1], r = lm0[r - 1];
        if (l >= r) have.insert({0, 0});
        else have.insert({l, r});
    }
    cout << have.size() << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}