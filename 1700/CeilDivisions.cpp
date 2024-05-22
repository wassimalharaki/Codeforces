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

int sqrd(int x) {
    return x * x;
}

void solve() {
    int n; cin >> n;

    int x = n;
    v<array<int, 2>> ans;
    for (int i = n - 1; i >= 2; i--)
        if (sqrd(i - 1) < x) {
            ans.push_back({x, i});
            ans.push_back({x, i});
            x = i;
        }
        else
            ans.push_back({i, x});

    if (x != 2)
        while (x > 1)
            ans.push_back({x, 2}), x = (x + 1) / 2;

    cout << ans.size() << nl;
    for (auto& [x, y] : ans)
        cout << x << " " << y << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}