#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 25;

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    auto b = a;

    auto bs = [&](int i, int x) {
        return lower_bound(a.begin() + i + 1, a.end(), x);
    };

    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            curr += bs(j, (1 << (i + 1)) - a[j]) - bs(j, (1 << i) - a[j]);
            curr += bs(j, (1 << (i + 2)) - a[j]) - bs(j, (1 << (i + 1)) + (1 << i) - a[j]);
        }

        for (int& x : a)
            x &= INT_MAX ^ (1 << i);
        sort(a.begin(), a.end());

        ans += (curr & 1) << i;
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