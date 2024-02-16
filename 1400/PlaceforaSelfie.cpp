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
   int n, m; cin >> n >> m;

    vi nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));
    vi ans(m, -INF);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        vi ok;
        auto it = lower_bound(all(nums), b);
        if (it != nums.end())
            ok.pb(*it);
        if (it != nums.begin())
            ok.pb(*(--it));
        bool found = 0;
        for (int& k : ok)
            if ((b - k) * (b - k) < 4 * a * c) {
                cout << "YES" << nl << k << nl;
                found = 1;
                break;
            }
        if (not found)
            cout << "NO" << nl;
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}