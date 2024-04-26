#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

map<char, array<int, 2>> id{
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {1, -1}},
    {'D', {1, 1}}
};

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    array<int, 2> curr{0, 0}, ans{1, 1};
    array<int, 4> ends{0, 0, 0, 0};

    auto fix = [&]() {
        ends[0] = min(ends[0], curr[0]);
        ends[1] = max(ends[1], curr[0]);
        ends[2] = min(ends[2], curr[1]);
        ends[3] = max(ends[3], curr[1]);
    };

    auto check = [&]() {
        return 1 - ends[0] <= m - ends[1] and 1 - ends[2] <= n - ends[3];
    };

    for (char& c : s) {
        curr[id[c][0]] += id[c][1];
        fix();
        if (not check()) break;
        ans = {1 - ends[2], 1 - ends[0]};
    }
    cout << ans[0] << " " << ans[1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}