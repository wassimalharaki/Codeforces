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
    int c, m, x; cin >> c >> m >> x;

    int lo = 0, hi = 1e8, answ;
    while (lo <= hi) {
        int teams = (lo + hi) / 2;
        bool ok = 1;

        if (teams > c or teams > m)
            ok = 0;
        
        int leftover = c - teams + m - teams + x;
        if (leftover < teams)
            ok = 0;
        
        if (ok)
            answ = teams, lo = teams + 1;
        else
            hi = teams - 1;
    }
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}