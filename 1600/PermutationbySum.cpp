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

bool can(int n, int x, int s) {
    int min = x * (x + 1) / 2;
    int max = x * (2 * n - x + 1) / 2;
    return min <= s and s <= max;
}

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;

    if (not can(n, r - l + 1, s)) {
        cout << -1 << nl;
        return;
    }

    v<int> ans(n);
    set<int> have;
    for (int i = 1; i <= n; i++)
        have.insert(i);

    auto fill = [&](int i, int m, auto&& fill) -> void {
        for (int x = m; x >= 1; x--)
            if (can(x - 1, i - l + 1, s - x)) {
                have.erase(x);
                ans[i] = x;
                s -= x;
                fill(i - 1, x - 1, fill);
                break;
            }
    };
    fill(r - 1, n, fill);
    
    for (int& a : ans) {
        if (a == 0) {
            a = *have.begin();
            have.erase(*have.begin());
        }
        cout << a << " ";
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