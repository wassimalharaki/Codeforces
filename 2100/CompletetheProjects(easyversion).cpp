#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, r; cin >> n >> r;

    v<array<int, 2>> pos, neg;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (y >= 0)
            pos.push_back({x, y});
        else
            neg.push_back({x, y});
    }
    sort(pos.begin(), pos.end());

    for (auto& [x, y] : pos)
        if (r >= x) r += y;
        else return void(cout << "NO" << nl);
    
    for (auto& [x, y] : neg)
        r += y;
    if (r < 0)
        return void(cout << "NO" << nl);
    if (neg.empty())
        return void(cout << "YES" << nl);
    
    int m = neg.size();
    v<int> dead(m);
    while (*min_element(dead.begin(), dead.end()) == 0) {
        bool ok = 0;
        for (int i = 0; i < m; i++)
            if (not dead[i] and r - neg[i][1] >= neg[i][0]) {
                r -= neg[i][1];
                dead[i] = 1;
                ok = 1;
            }
        if (not ok) break;
    }
    cout << (*min_element(dead.begin(), dead.end()) ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}