#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    int ans = 0, ones = 0;
    for (int& x : a) {
        cin >> x;
        int y = min(ones, x / 2);
        ans += y;
        ones -= y;
        x -= 2 * y;
        ans += x / 3;
        ones += x % 3;
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