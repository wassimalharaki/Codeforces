#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

vi a(39), b(39);

void solve() {
    int n; cin >> n;
    int c = *lower_bound(all(b), n);
    for (int i = 38; i >= 0; i--)
        if (c - a[i] >= n)
            c -= a[i];
    cout << c << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    a[0] = b[0] = 1;
    for (int i = 1; i < 39; i++) {
        a[i] = a[i - 1] * 3;
        b[i] = b[i - 1] + a[i];
    }

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}