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
    string s; cin >> s;
    int n = s.size();

    if (s[0] == 'B' or s[n - 1] == 'B') {
        cout << count(all(s), 'A') << nl;
        return;
    }

    v<pair<char, int>> blocks{mp(s[0], 1)};
    for (int i = 1; i < n; i++)
        if (s[i] == blocks.back().F)
            blocks.back().S++;
        else
            blocks.pb(mp(s[i], 1));
    
    for (int i = 0; i < blocks.size(); i++)
        if (blocks[i].F == 'B' and blocks[i].S > 1) {
            cout << count(all(s), 'A') << nl;
            return;
        }

    vi nums;
    for (int i = 0; i < blocks.size(); i++)
        if (blocks[i].F == 'A')
            nums.pb(blocks[i].S);
    sort(all(nums));
    cout << accumulate(1 + all(nums), 0ll) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}