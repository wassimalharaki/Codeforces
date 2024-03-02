#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    map<char, pair<int, int>> dir{
        {'L', {-1, 0}},
        {'R', {1, 0}},
        {'U', {0, 1}},
        {'D', {0, -1}}
    };

    map<pair<int, int>, int> pos;
    pos[{0, 0}] = -1;
    int x = 0, y = 0, ans = LONG_LONG_MAX;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        auto& p = dir[s[i]];
        x += p.first, y += p.second;
        if (pos.count({x, y})) {
            int diff = i - pos[{x, y}];
            if (diff < ans) {
                ans = diff;
                l = pos[{x, y}] + 1;
                r = i + 1;
            }
        }
        pos[{x, y}] = i;
    }
    if (ans == LONG_LONG_MAX)
        cout << -1 << nl;
    else
        cout << l + 1 << " " << r << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}