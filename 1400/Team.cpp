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

void solve() {
    int n, m; cin >> m >> n;

    vpii ans;
    if (n > m)
        ans.pb(mp(1, 1)), n--;
    else
        ans.pb(mp(0, 1)), m--;

    while (1)
        if (ans.back().F) {
            if (m == 0) break;
            ans.pb(mp(0, 1)), m--;
        }
        else {
            if (n == 0) break;
            ans.pb(mp(1, 1)), n--;
        }
    
    for (int i = 0; i < ans.size() and n; i++)
        if (ans[i].F) ans[i].S++, n--;
    
    if (n or m)
        cout << -1;
    else
        for (auto& [a, j] : ans)
            for (int i = 0; i < j; i++)
                cout << a;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}