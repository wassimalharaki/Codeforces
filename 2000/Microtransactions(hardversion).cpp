#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 2e5 + 10;

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> b(n);
    for (int i = 0; i < m; i++) {
        int d, t; cin >> d >> t;
        b[--t].push_back(d);
    }

    for (auto& x : b)
        sort(x.begin(), x.end());

    auto check = [&](int k) -> bool {
        int sum = accumulate(a.begin(), a.end(), 0ll);
        v<v<int>> buyon(k + 1);
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(b[i].begin(), b[i].end(), k);
            if (it == b[i].begin()) continue;
            buyon[*(--it)].push_back(i);
        }

        int curr = 0;
        for (int i = 1; i <= k; i++) {
            curr++;
            for (int& j : buyon[i]) {
                int sub = min(a[j], curr);
                curr -= sub;
                sum -= sub;
            }
        }
        return 2 * sum <= curr;
    };

    int lo = 0, hi = 2 * N, ans = INT_MAX;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        
        if (check(mid))
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
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