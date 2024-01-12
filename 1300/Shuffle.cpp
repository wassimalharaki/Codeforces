#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
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
    return l1 <= r2 and l1 >= l2 or r1 >= l2 and r1 <= r2;
}

void solve() {
    int n, x, m; cin >> n >> x >> m;

    int lmin = x, rmax = x;
    while (m--) {
        int l, r; cin >> l >> r;
        if (not intersect(l, r, lmin, rmax))
            continue;
        lmin = min(lmin, l);
        rmax = max(rmax, r);
    }
    cout << rmax - lmin + 1 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}