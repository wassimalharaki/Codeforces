#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, p; cin >> n >> p;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    v<int> ans;
    for (int x = max(a.front(), a.back() - n + 1); x < max(a.back(), p); x++) {
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            int le = upper_bound(a.begin(), a.end(), x + i) - a.begin() - i;
            ok &= le < p and le > 0;
        }
        if (ok) ans.push_back(x);
    }

    cout << ans.size() << nl;
    for (int& x : ans)
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