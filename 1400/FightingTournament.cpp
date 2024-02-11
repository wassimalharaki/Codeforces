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
    int n, q; cin >> n >> q;

    deque<pii> nums;
    vi rem(n);
    for (int i = 0; i < n; i++) {
        cin >> rem[i];
        nums.pb(mp(rem[i], i));
    }

    vvi wins(n);
    int r = 1;
    while (1) {
        auto [a, i] = nums.front();
        nums.pop_front();
        auto [b, j] = nums.front();
        nums.pop_front();

        if (a == n) {
            wins[i].pb(r);
            break;
        }
        if (b == n) {
            wins[j].pb(r);
            break;
        }

        if (a > b) {
            nums.push_front(mp(a, i));
            nums.pb(mp(b, j));
            wins[i].pb(r);
        }
        else {
            nums.pb(mp(a, i));
            nums.push_front(mp(b, j));
            wins[j].pb(r);
        }
        r++;
    }

    while (q--) {
        int i, k; cin >> i >> k;
        i--;
        if (rem[i] == n)
            cout << max(0ll, k - wins[i][0] + 1) << nl;
        else
            cout << upper_bound(all(wins[i]), k) - wins[i].begin() << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}