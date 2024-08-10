#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    map<int, int> have{{0, 0}};
    for (int i = 0; i < n; i++) {
        v<array<int, 2>> nxt;
        for (auto& [g, c] : have)
            nxt.push_back({__gcd(g, a[i]), c + b[i]});
        for (auto& [g, c] : nxt)
            if (have.count(g))
                have[g] = min(have[g], c);
            else
                have[g] = c;
    }
    cout << (have[1] ? have[1] : -1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}