#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 30;

void solve() {
    int n, q; cin >> n >> q;

    v<v<array<int, 2>>> adj(n);
    while (q--) {
        int i, j, x; cin >> i >> j >> x;
        i--, j--;
        adj[i].push_back({j, x});
        adj[j].push_back({i, x});
    }

    v<int> a(n);
    for (int i = 0; i < n; i++)
        if (adj[i].size()) {
            a[i] = INT_MAX;
            for (auto& [j, x] : adj[i])
                a[i] &= x;
        }

    for (int i = 0; i < n; i++)
        if (adj[i].size())
            for (int bit = N - 1; bit >= 0; bit--)
                if ((1 << bit) & a[i]) {
                    a[i] ^= (1 << bit);
                    bool ok = 1;
                    for (auto& [j, x] : adj[i])
                        ok &= (a[i] | a[j]) == x;
                    if (not ok) a[i] ^= (1 << bit);
                }

    for (int& x : a)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}