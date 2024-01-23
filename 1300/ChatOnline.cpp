#include <bits/stdc++.h>

using namespace std;

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

bool intersect(int l1, int r1, int l2, int r2) {
    if (r1 - l1 > r2 - l2)
        return intersect(l2, r2, l1, r1);
    return (l1 >= l2 and l1 <= r2) or (r1 >= l2 and r1 <= r2);
}

void solve() {
    int p, q; cin >> p >> q;
    int l, r; cin >> l >> r;

    vpii a(p), b(q);
    for (pii& x : a) cin >> x.F >> x.S;
    for (pii& x : b) cin >> x.F >> x.S;

    int ans = 0;
    for (int i = l; i <= r; i++) {
        bool ok = 0;
        for (pii& x : a)
            for (pii& y : b)
                if (intersect(x.F, x.S, y.F + i, y.S + i))
                    ok = 1;
        ans += ok;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}