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

    v<pair<int, char>> blocks{{1, s[0]}};
    for (int i = 1; i < s.size(); i++)
        if (s[i] == blocks.back().S)
            blocks.back().F++;
        else
            blocks.pb(mp(1, s[i]));

    if (blocks[0].F >= 3)
        blocks[0].F = 2;
    for (int i = 1; i < blocks.size(); i++)
        if (blocks[i].F >= 3)
            blocks[i].F = (blocks[i - 1].F == 2 ? 1 : 2);
        else if (blocks[i].F == 2 and blocks[i - 1].F == 2)
            blocks[i].F = 1;
    
    string t;
    for (auto& [count, ch] : blocks)
        t += string(count, ch);
    cout << t << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}