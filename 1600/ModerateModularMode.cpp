#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

bool check(int x, int y, int n) {
    return n % x == y % n;
}

int get(int x, int y) {
    if (x > y)
        return x + y;
    int n = (x + y) / 2;
    int m1 = n % x, m2 = y % n;
    int diff = m2 - m1;
    n += diff / x * x;
    m1 = n % x, m2 = y % n;
    diff = m2 - m1;
    n += diff / 2;
    return n;
}

void solve() {
    int x, y; cin >> x >> y;
    cout << get(x, y) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}