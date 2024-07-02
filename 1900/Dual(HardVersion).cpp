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
    
    v<int> a(n);
    for (int& x : a) cin >> x;
    v<int> neg(a), pos(a);
    v<array<int, 2>> neg_ops, pos_ops;
    int min = *min_element(a.begin(), a.end());
    int max = *max_element(a.begin(), a.end());

    if (min >= 0) {
        cout << n - 1 << nl;
        for (int i = 1; i < n; i++)
            cout << i + 1 << " " << i << nl;
        return;
    }

    if (max <= 0) {
        cout << n - 1 << nl;
        for (int i = n; i > 1; i--)
            cout << i - 1 << " " << i << nl;
        return;
    }

    int imin = 0;
    for (int i = 0; i < n; i++)
        if (neg[i] < neg[imin])
            imin = i;

    while (abs(neg[imin]) < max) {
        neg_ops.push_back({imin, imin});
        neg[imin] += neg[imin];
    }

    for (int i = 0; i < n; i++)
        if (neg[i] > 0) {
            neg_ops.push_back({i, imin});
            neg[i] += neg[imin];
        }
    
    for (int i = n - 1; i >= 1; i--)
        if (neg[i - 1] > neg[i]) {
            neg_ops.push_back({i - 1, i});
            neg[i - 1] += neg[i];
        }

    int imax = 0;
    for (int i = 0; i < n; i++)
        if (pos[i] > pos[imax])
            imax = i;
    
    while (pos[imax] < abs(min)) {
        pos_ops.push_back({imax, imax});
        pos[imax] += pos[imax];
    }

    for (int i = 0; i < n; i++)
        if (pos[i] < 0) {
            pos_ops.push_back({i, imax});
            pos[i] += pos[imax];
        }
    
    for (int i = 1; i < n; i++)
        if (pos[i] < pos[i - 1]) {
            pos_ops.push_back({i, i - 1});
            pos[i] += pos[i - 1];
        }
    
    if (neg_ops.size() < pos_ops.size()) {
        cout << neg_ops.size() << nl;
        for (auto& [i, j] : neg_ops)
            cout << i + 1 << " " << j + 1 << nl;
    }
    else {
        cout << pos_ops.size() << nl;
        for (auto& [i, j] : pos_ops)
            cout << i + 1 << " " << j + 1 << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}