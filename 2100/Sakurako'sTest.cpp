#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, q; cin >> n >> q;

    v<int> a(n), cnt(n + 1);
    for (int& x : a)
        cin >> x, cnt[x]++;
    v<int> pref(n + 2);
    partial_sum(cnt.begin(), cnt.end(), pref.begin() + 1);

    v<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int lo = 0, hi = i - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int le = 0;
            for (int j = 0; j <= n; j += i)
                le += pref[min(n + 1, j + mid + 1)] - pref[j];
            
            if (le >= n / 2 + 1)
                dp[i] = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
    }

    while (q--) {
        int x; cin >> x;
        cout << dp[x] << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}