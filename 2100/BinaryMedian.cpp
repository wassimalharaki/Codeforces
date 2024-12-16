#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '1')
                a[i] += 1ll << (m - j - 1);
    }
    sort(a.begin(), a.end());
    int k = ((1ll << m) - n - 1) / 2;

    auto le = [&](int x) -> int {
        return x - (lower_bound(a.begin(), a.end(), x) - a.begin());
    };

    int lo = 0, hi = 1ll << m, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (le(mid) <= k)
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }

    for (int i = m - 1; i >= 0; i--)
        cout << (((1ll << i) & ans) > 0);
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}