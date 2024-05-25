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

    v<map<int, int>> topic(n + 1), diff(n + 1);
    v<int> topic_cnt(n + 1), diff_cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        topic_cnt[a]++;
        topic[a][b]++;
        diff_cnt[b]++;
        diff[b][a]++;
    }

    int ans = n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++)
        if (topic_cnt[i] >= 2)
            for (auto& [d, cnt] : topic[i]) {
                int x = cnt;
                x *= topic_cnt[i] - cnt;
                x *= diff_cnt[d] - diff[d][i];
                ans -= x;
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