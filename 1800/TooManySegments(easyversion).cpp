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

const int N = 201;

void solve() {
    int n, k; cin >> n >> k;

    v<set<array<int, 2>>> left(N);
    v<set<int>> right(N);
    
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        left[l].insert({r, i});
        right[r].insert(i);
    }

    v<int> ans;
    set<array<int, 2>> curr;
    for (int i = 1; i < N; i++) {
        for (auto [r, j] : left[i])
            curr.insert({r, j});

        while (curr.size() > k) {
            auto [r, j] = *curr.rbegin();
            curr.erase(--curr.end());
            ans.push_back(j);
            right[r].erase(j);
        }

        for (auto j : right[i])
            curr.erase({i, j});
    }

    cout << ans.size() << nl;
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}