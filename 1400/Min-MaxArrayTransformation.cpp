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

    vi a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    int r = n - 1;
    vi min(n), max(n);
    for (int i = n - 1; i >= 0; i--) {
        int l = lower_bound(all(b), a[i]) - b.begin();
        min[i] = b[l] - a[i];
        max[i] = b[r] - a[i];
        if (l == i)
            r = i - 1;
    }

    for (int& x : min)
        cout << x << " ";
    cout << nl;
    for (int& x : max)
        cout << x << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}