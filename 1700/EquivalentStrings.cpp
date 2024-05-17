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

string s, t;

bool check(array<int, 2>& l, array<int, 2>& r) {
    for (int i = l[0], j = r[0]; i <= l[1]; i++, j++)
        if (s[i] != t[j])
            return 0;
    return 1;
}

bool f(array<int, 2>& l, array<int, 2>& r) {
    if (check(l, r)) return 1;
    int n = l[1] - l[0] + 1;
    if (n & 1) return 0;
    n >>= 1;

    array<int, 2> l1{l[0], l[0] + n - 1};
    array<int, 2> l2{l[0] + n, l[1]};
    array<int, 2> r1{r[0], r[0] + n - 1};
    array<int, 2> r2{r[0] + n, r[1]};

    bool a = f(l1, r1);
    if (a)
        return f(l2, r2);
    else
        return f(l1, r2) and f(l2, r1);
}

void solve() {
    cin >> s >> t;
    int n = s.size();
    array<int, 2> l = {0, n - 1};
    cout << (f(l, l) ? "YES" : "NO");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}