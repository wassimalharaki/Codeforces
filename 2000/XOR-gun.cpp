#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    int LIM = 32;

    int ans = 1e9;
    for (int i = 0; i < n - 1; i++) {
        int l = max(0ll, i - LIM), r = min(n - 1, i + LIM);
        int x = 0;
        for (int j = i; j >= l; j--) {
            x ^= a[j];
            int y = 0;
            for (int k = i + 1; k <= r; k++) {
                y ^= a[k];
                if (x > y)
                    ans = min(ans, k - j - 1);
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}