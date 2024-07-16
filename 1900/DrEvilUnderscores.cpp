#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    auto go = [](v<int>& a, int i, auto&& go) -> int {
        if (i < 0 or a.empty())
            return 0;

        v<int> on, off;
        for (int& x : a)
            if ((1 << i) & x)
                on.push_back(x);
            else
                off.push_back(x);
                
        if (on.empty() or off.empty())
            return go(a, i - 1, go);
        else
            return (1 << i) + min(go(on, i - 1, go), go(off, i - 1, go));
    };
    cout << go(a, 30, go) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}