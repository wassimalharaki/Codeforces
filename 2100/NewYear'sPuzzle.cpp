#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

bool valid(v<array<int, 2>>& a) {
    int n = a.size();
    bool ok = (n & 1) ^ 1;
    for (int i = 0; i < n; i += 2)
        if (a[i][1] == a[i + 1][1])
            ok &= (a[i + 1][0] - a[i][0]) & 1;
        else
            ok &= ((a[i + 1][0] - a[i][0]) & 1) ^ 1;
    return ok;
}

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 2>> a(m);
    for (auto& [c, r] : a)
        cin >> r >> c;
    sort(a.begin(), a.end());

    bool ok = 1;
    v<array<int, 2>> b;
    for (auto& [c, r] : a)
        if (b.empty() or b.back()[0] != c)
            b.push_back({c, r});
        else {
            b.pop_back();
            ok &= valid(b);
            b.clear();
        }
    ok &= valid(b);
    cout << (ok ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}