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

void solve() {
    int n, k; cin >> n >> k;

    map<int, int> map;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        map[a]++;
    }

    vi rem;
    for (auto& [key, val] : map)
        if (val < k) rem.pb(key);
    for (auto& i : rem) map.erase(i);

    if (map.empty()) {
        cout << -1 nl;
        return;
    }

    int l = map.begin() -> F, r = l;
    int cl = l, cr = l;
    for (auto it = ++map.begin(); it != map.end(); it++) {
        int a = it -> F, b = (--it) -> F; it++;
        if (a - b == 1)
            cr++;
        else {
            if (cr - cl > r - l)
                r = cr, l = cl;
            cl = a, cr = a;
        }
    }
    if (cr - cl > r - l)
        r = cr, l = cl;
    cout << l << " " << r nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}