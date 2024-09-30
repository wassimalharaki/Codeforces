#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    v<map<int, int>> cnt(n + 1);
    for (int& x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[a[i]][x]++;
    }

    int64_t ans = 0;
    for (int i = 1; i <= n; i++)
        if (cnt[i].size())
            for (int j = i; 1ll * j * i <= 2 * n and j <= n; j++)
                if (cnt[j].size()) {
                    int prod = j * i;
                    if (i == j) {
                        int64_t curr = 0;
                        for (auto& [x, y] : cnt[i]) {
                            if (x >= prod) break;
                            if (prod - x == x)
                                curr += 1ll * y * (y - 1);
                            else if (cnt[i].count(prod - x))
                                curr += 1ll * y * cnt[i][prod - x];
                        }
                        ans += curr >> 1;
                    }
                    else if (cnt[j].size() < cnt[i].size())
                        for (auto& [x, y] : cnt[j]) {
                            if (x >= prod) break;
                            if (cnt[i].count(prod - x))
                                ans += 1ll * y * cnt[i][prod - x];
                        }
                    else
                        for (auto& [x, y] : cnt[i]) {
                            if (x >= prod) break;
                            if (cnt[j].count(prod - x))
                                ans += 1ll * y * cnt[j][prod - x];
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