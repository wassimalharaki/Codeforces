#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, q; cin >> n >> q;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    while (q--) {
        int k; cin >> k;
        if (k <= n) {
            int ans = LLONG_MAX;
            for (int i = 0; i < n; i++)
                ans = min(ans, a[i] + max(0ll, k - i));
            cout << ans << " ";
        }
        else {
            map<int, int> have;
            for (int i = 0; i < n; i++)
                have[a[i] + ((i == n - 1 and ((k - n) & 1)) ? 0 : k - i)]++;
            int m = (k - n + ((k - n) & 1)) / 2;
            while (m) {
                auto& [x, cnt] = *have.rbegin();
                if (cnt > m) {
                    have[x - 1] += m;
                    cnt -= m;
                    m = 0;
                }
                else if (have.size() == 1) {
                    int y = (m + cnt - 1) / cnt;
                    have[x - y] += cnt;
                    m = 0;
                }
                else {
                    auto& [y, _] = *(++have.rbegin());
                    m = max(0ll, m - (x - y) * cnt);
                    have[y] += cnt;
                    have.erase(x);
                }
            }
            cout << (*have.begin()).first << " ";
        }
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}