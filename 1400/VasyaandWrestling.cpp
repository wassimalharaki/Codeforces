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

void solve() {
    int n; cin >> n;

    vi a, b;
    bool ok;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > 0)
            a.pb(x), ok = 1;
        else
            b.pb(-x), ok = 0;
    }

    int x = accumulate(all(a), 0ll);
    int y = accumulate(all(b), 0ll);
    if (x > y)
        cout << "first";
    else if (y > x)
        cout << "second";
    else {
        if (a > b)
            cout << "first";
        else if (b > a)
            cout << "second";
        else
            cout << (ok ? "first" : "second");
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}