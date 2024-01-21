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
    string s; cin >> s;

    v<pair<int, char>> occ{{1, s[0]}};
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1])
            occ.back().F++;
        else
            occ.pb(mp(1, s[i]));
    if (occ.back().S == 'o') occ.pop_back();

    if (occ.empty()) {
        cout << 0;
        return;
    }

    if (occ.begin() -> S == 'o') occ.erase(occ.begin());
    
    for (int i = 0; i < occ.size(); i++)
        if (occ[i].S == 'v')
            occ[i].F--;
    
    int count = 0, prev = 0;
    vi pre(occ.size());
    for (int i = occ.size() - 1; i >= 0; i--) {
        if (occ[i].S == 'v') {
            count += occ[i].F;
            continue;
        }
        pre[i] = occ[i].F * count + prev;
        prev = pre[i];
    }

    int ans = 0;
    for (int i = 0; i < occ.size() - 1; i++) {
        if (occ[i].S == 'o') continue;
        ans += occ[i].F * pre[i + 1];
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