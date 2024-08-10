#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int w, m; cin >> w >> m;

    if (w == 2) {
        cout << "YES" << nl;
        return;
    }

    int y = 1;
    v<int> a;
    while (y <= 2 * m) {
        a.push_back(y);
        y *= w;
    }
    int n = a.size();

    for (int mask = 0; mask < (1 << n); mask++) {
        int x = m;
        for (int i = 0; i < n; i++)
            if ((1 << i) & mask)
                x += a[i];
        for (int i = n - 1; i >= 0; i--)
            if (!((1 << i) & mask) and a[i] <= x)
                x -= a[i];
        if (x == 0) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}