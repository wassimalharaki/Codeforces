#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

void solve() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    set<pii> visited;
    visited.insert(mp(sx, sy));
    cout << sx << " " << sy nl;
    visited.insert(mp(1, sy));
    cout << 1 << " " << sy nl;
    visited.insert(mp(1, 1));
    cout << 1 << " " << 1 nl;

    for (int i = 1; i <= n; i++)
        if (i & 1) {
            for (int j = 1; j <= m; j++)
                if (visited.find(mp(i, j)) == visited.end())
                    cout << i << " " << j nl;
        }
        else {
            for (int j = m; j > 0; j--)
                if (visited.find(mp(i, j)) == visited.end())
                    cout << i << " " << j nl;
        }
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;

    while(T--)
        solve();

    return 0;
}