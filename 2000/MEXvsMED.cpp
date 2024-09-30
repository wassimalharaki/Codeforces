#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int ans = 1, l = n + 1, r = -1;
    for (int i = 1; i < n; i++) {
        l = min(l, pos[i - 1]);
        r = max(r, pos[i - 1]);
        if (l <= pos[i] and pos[i] <= r)
            continue;

        if (pos[i] < l) {
            for (int lb = pos[i] + 1; lb <= l; lb++) {
                int rb = min(n - 1, lb + 2 * i - 1);
                ans += max(0ll, rb - r + 1);
            }
        }
        else if (pos[i] > r) {
            for (int rb = pos[i] - 1; rb >= r; rb--) {
                int lb = max(0ll, rb - 2 * i + 1);
                ans += max(0ll, l - lb + 1);
            }
        }
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