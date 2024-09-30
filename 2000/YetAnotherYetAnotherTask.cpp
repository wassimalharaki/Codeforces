#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int ans = 0;
    v<int> b(n, INT_MIN);
    for (int ub = -30; ub <= 30; ub++) {
        for (int i = 0; i < n; i++)
            if (a[i] <= ub)
                b[i] = a[i];
        int curr = 0, min = 0;
        for (int& x : b) {
            curr += x;
            ans = max(ans, curr - min - ub);
            min = std::min(min, curr);
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}