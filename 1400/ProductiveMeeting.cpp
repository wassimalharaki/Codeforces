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

    set<pii> nums;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a)
            nums.insert(mp(a, i + 1));
    }

    vpii ans;
    while (nums.size() > 1) {
        pii a = *nums.rbegin();
        pii b = *(++nums.rbegin());
        nums.erase(a); nums.erase(b);
        ans.pb(mp(a.S, b.S));
        a.F--, b.F--;
        if (a.F)
            nums.insert(a);
        if (b.F)
            nums.insert(b);
    }

    cout << ans.size() << nl;
    for (pii& p : ans)
        cout << p.F << " " << p.S << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}