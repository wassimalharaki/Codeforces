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

    if (n & 1 ^ 1) {
        for (int i = n / 2; i <= n + n / 2; i++)
            if (i != n)
                cout << i << " ";
        cout << nl;
    }
    else {
        int sqr = (n + 2) * (n + 2);
        int lo = 1, hi = 1e9, x = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int l = (2 * mid + n - 2) * (n - 1) / 2 + mid + n + 2;
            int r = (2 * mid + n + 6) * (n - 1) / 2 + mid;
            if (l <= sqr and sqr <= r)
                x = mid, hi = mid - 1;
            else if (sqr < l)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        v<int> ans{x};
        for (int i = x + 4; i <= x + n + 2; i++)
            ans.push_back(i);

        int sum = accumulate(ans.begin(), ans.end(), 0ll);
        for (int i = 1; i < n - 1 and sum > sqr; i++) {
            int diff = min(sum - sqr, 3ll);
            ans[i] -= diff;
            sum -= diff;
        }

        for (int& x : ans)
            cout << x << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}