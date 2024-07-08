#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<int> ans;
    int cnt = 1, sz = 1;
    while (sz < n) {
        if (2 * cnt + sz >= n) {
            ans.push_back(n - sz - cnt);
            cnt += n - sz - cnt;
        }
        else {
            int x = min((n - sz - 2 * cnt) / 2, cnt);
            x = max(0ll, x);
            ans.push_back(x);
            cnt += x;
        }
        sz += cnt;
    }

    cout << ans.size() << nl;
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}