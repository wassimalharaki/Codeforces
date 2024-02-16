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
    string s; cin >> s;

    string min_s = s;
    int min_k = 1;
    for (int k = 2; k <= n; k++) {
        string a = s.substr(0, k - 1);
        string t = s.substr(k - 1, n);
        if ((n - k + 1) & 1)
            reverse(all(a));
        t += a;
        if (t < min_s)
            min_s = t, min_k = k;
    }
    cout << min_s << nl << min_k << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}