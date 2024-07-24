#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int get(int x, int y, int z) {
    if (x >= y) return 0;
    return (y - x + z - 1) / z;
}

void solve() {
    int n, c; cin >> n >> c;

    v<int> a(n), b(n - 1);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    int ans = 1e18, curr = 0, x = 0;
    for (int i = 0; i < n; i++) {
        ans = min(ans, curr + get(x, c, a[i]));
        if (i == n - 1) continue;
        int need = get(x, b[i], a[i]);
        curr += need + 1;
        x += need * a[i] - b[i];
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}