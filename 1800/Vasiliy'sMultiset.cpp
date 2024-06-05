#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

const int N = 30;

void solve() {
    int q; cin >> q;

    array<map<int, int>, 30> a;
    auto add = [&](int x) -> void {
        for (int i = 0; i < N; i++) {
            int y = x & ((1 << N) - (1 << i));
            ++a[i][y];
        }
    };

    auto rem = [&](int x) -> void {
        for (int i = 0; i < N; i++) {
            int y = x & ((1 << N) - (1 << i));
            --a[i][y];
        }
    };

    auto get = [&](int x) -> int {
        int y = 0;
        for (int i = N - 1; i >= 0; i--)
            if ((1 << i) & x) {
                if (!a[i].count(y) or !a[i][y])
                    y += (1 << i);
            }
            else {
                if (a[i].count(y + (1 << i)) and a[i][y + (1 << i)])
                    y += (1 << i);
            }
        return y ^ x;
    };
    add(0);

    while (q--) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == '+')
            add(x);
        else if (c == '-')
            rem(x);
        else
            cout << get(x) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}