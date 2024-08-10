#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    int x = 0;
    v<array<int, 2>> a(n);
    for (auto& [l, r] : a)
        cin >> l;
    for (auto& [l, r] : a) {
        cin >> r;
        x += r - l + 1;
    }

    if (x < k) {
        cout << -1 << nl;
        return;
    }

    int cnt = 0, curr = 0, ones = 0, ans = LLONG_MAX;
    for (auto& [l, r] : a) {
        if (cnt >= k) break;
        if (cnt + ones + r - l + 1 >= k) {
            int use = min(r - l + 1, k - cnt);
            int reach = cnt + use;
            ans = min(ans, curr + 2 + l + use - 1 + (k - reach) * 2);
        }
        if (r == l)
            ones++;
        else
            cnt += r - l + 1, curr += 2;
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