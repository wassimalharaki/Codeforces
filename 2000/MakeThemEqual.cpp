#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    int x = accumulate(a.begin(), a.end(), 0ll);

    if (x % n) {
        cout << -1 << nl;
        return;
    }
    int y = x / n;

    v<array<int, 3>> ans;
    for (int i = 1; i < n; i++) {
        int j = i + 1;
        if (a[i] % j and a[0] >= j - a[i] % j) {
            ans.push_back({1, j, j - a[i] % j});
            a[0] -= j - a[i] % j;
            a[i] += j - a[i] % j;
        }
        int can = a[i] / j;
        ans.push_back({j, 1, can});
        a[0] += can * j;
        a[i] -= can * j;
    }

    for (int i = 1; i < n; i++)
        ans.push_back({1, i + 1, y});
    
    cout << ans.size() << nl;
    for (auto& [i, j, k] : ans)
        cout << i << " " << j << " " << k << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}