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
    int n, x; cin >> n >> x;
    string s; cin >> s;

    map<int, int> cnt;
    int end = 0, l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        end += (s[i] == '1' ? -1 : 1);
        l = min(l, end);
        r = max(r, end);
        cnt[end]++;
    }

    if (end == 0) {
        cout << (l <= x and x <= r ? -1 : 0) << nl;
        return;
    }

    int ans = x == 0;
    int lo = 0, hi = 1e9, k = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (x - mid * end >= l) {
            k = mid;
            end > 0 ? lo = mid + 1 : hi = mid - 1;
        }
        else
            end > 0 ? hi = mid - 1 : lo = mid + 1;
    }

    for (; x - k * end <= r and k >= 0; end > 0 ? k-- : k++)
        ans += cnt[x - k * end];
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}