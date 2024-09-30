#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<v<int>> grps{v<int>(n)};
    for (int& x : grps[0]) cin >> x;

    int x = 0, inv = 0;
    for (int bit = (1 << 30); bit; bit >>= 1) {
        int inv_on = 0, inv_off = 0;

        v<v<int>> ngrps;
        for (auto& a : grps) {
            v<int> on, off;

            for (int& y : a)
                if (bit & y) {
                    on.push_back(y);
                    inv_on += off.size();
                }
                else {
                    off.push_back(y);
                    inv_off += on.size();
                }

            if (on.size())
                ngrps.emplace_back(on);
            if (off.size())
                ngrps.emplace_back(off);
        }

        if (inv_off <= inv_on)
            inv += inv_off;
        else
            inv += inv_on, x += bit;
        grps.swap(ngrps);
    }
    cout << inv << " " << x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}