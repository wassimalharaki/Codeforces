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

bool intersect(array<int, 2>& l, array<int, 2>& r) {
    return (l[0] >= r[0] and l[0] <= r[1]) or (l[1] >= r[0] and l[1] <= r[1])
        or (l[0] <= r[0] and l[1] >= r[1]);
}

array<int, 2> get(int a, int b, int n) {
    if (n == 1) return {1, a * n - b * (n - 1)};
    return {max(0ll, a * (n - 1) - b * (n - 2)) + 1, a * n - b * (n - 1)};
}

void solve() {
    int q; cin >> q;

    array<int, 2> h{-1, -1};
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, n; cin >> a >> b >> n;
            auto x = get(a, b, n);
            if (h != array<int, 2>{-1, -1}) {
                if (intersect(x, h)) {
                    cout << 1 << " ";
                    h[0] = max(h[0], x[0]);
                    h[1] = min(h[1], x[1]);
                }
                else
                    cout << 0 << " ";
            }
            else {
                h = x;
                cout << 1 << " ";
            }
        }
        else {
            int a, b; cin >> a >> b;
            if (h == array<int, 2>{-1, -1})
                cout << -1 << " ";
            else {
                int y = max((h[0] + a - 2 * b - 1) / (a - b), 1ll);
                int x = a * y - b * (y - 1);
                cout << (x >= h[1] ? y : -1) << " ";
            }
        }
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