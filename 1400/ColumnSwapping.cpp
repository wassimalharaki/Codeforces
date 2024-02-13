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

    vvi nums(n, vi(m));
    for (vi& a : nums)
        for (int& b : a)
            cin >> b;
    
    pii p{-1, -1};
    vi avail(m);
    iota(all(avail), 0ll);
    for (vi& a : nums) {
        if (p.F == -1) {
            for (int i = 0; i < m - 1 and p.F == -1; i++)
                if (a[i + 1] < a[i]) {
                    p.F = i;
                    break;
                }
            while (p.F and a[p.F] == a[p.F - 1])
                p.F--;
        }
        if (p.F == -1) continue;

        vi ind;
        int min = *min_element(p.F + all(a));
        for (int i = p.F; i < m; i++)
            if (a[i] == min)
                ind.pb(i);

        int x = 0, y = 0;
        vi dupe;
        while (x < avail.size() and y < ind.size())
            if (avail[x] == ind[y])
                dupe.pb(avail[x]), x++, y++;
            else if (avail[x] > ind[y])
                y++;
            else
                x++;
        avail = dupe;
    }

    if (p.F == -1) {
        cout << 1 << " " << 1 << nl;
        return;
    }

    if (avail.empty()) {
        cout << -1 << nl;
        return;
    }
    p.S = avail.back();

    for (vi& a : nums)
        swap(a[p.F], a[p.S]);

    bool ok = 1;
    for (vi& a : nums)
        if (not is_sorted(all(a)))
            ok = 0;
    
    if (ok)
        cout << p.F + 1 << " " << p.S + 1 << nl;
    else
        cout << -1 << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}