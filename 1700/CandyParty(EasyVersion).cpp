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

    v<int> a(n);
    for (int& x : a) cin >> x;

    int av = accumulate(a.begin(), a.end(), 0ll);
    if (av % n) {
        cout << "No" << nl;
        return;
    }
    av /= n;

    v<int> bits(33);
    for (int& x : a) {
        int diff = abs(x - av);
        bool start = 0, end = 0;
        int l = 0, r = 0;
        for (int i = 0; i < 32; i++)
            if ((1ll << i) & diff) {
                if (end) {
                    cout << "No" << nl;
                    return;
                }
                if (start)
                    r = i;
                else {
                    start = 1;
                    l = i;
                    r = i;
                }
            }
            else if (start) end = 1;

        if (x > av)
            bits[r + 1]++, bits[l]--;
        else if (x < av)
            bits[l]++, bits[r + 1]--;
    }
    sort(bits.begin(), bits.end());

    cout << (bits[0] == bits[32] ? "Yes" : "No") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}