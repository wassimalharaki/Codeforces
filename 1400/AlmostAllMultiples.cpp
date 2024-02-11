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
    int n, x; cin >> n >> x;

    if (n % x) {
        cout << -1 << nl;
        return;
    }

    vi ans(n);
    ans[0] = x, ans[n - 1] = 1;
    for (int i = 1; i < n - 1; i++)
        ans[i] = i + 1;
    if (x != n)
        ans[x - 1] = n;
    
    x--;
    for (int i = x + 1; i < n - 1; i++) {
        if (ans[x] % ans[i]) continue;
        if (ans[i] % (x + 1)) continue;
        swap(ans[i], ans[x]);
        x = i;
    }
    
    for (int& a : ans) cout << a << " ";
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