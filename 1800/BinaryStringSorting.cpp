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

const int N = 1'000'000'000'000;

void solve() {
    string s; cin >> s;
    int n = s.size();

    while (s.size() and s.back() == '1')
        s.pop_back();
    n = s.size();
    int j = s.find_first_of('1');
    
    if (not n or j == -1) {
        cout << 0 << nl;
        return;
    }
    s = s.substr(j, n - j);
    n = s.size();

    v<array<int, 2>> blocks{{0, 1}};
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1] or s[i] == '0')
            blocks.back()[s[i] - '0']++;
        else
            blocks.push_back({0, 1});
    n = blocks.size();
    
    int ans = 1e18, left = 0, right = 0;
    for (int i = 0; i < n; i++)
        right += blocks[i][0] * (N + 1);

    for (int i = 0; i < n; i++) {
        right -= blocks[i][0] * (N + 1);
        if (blocks[i] == array<int, 2>{1, 1})
            ans = min(ans, left + right + N);
        else
            ans = min(ans, left + right + min(blocks[i][0], blocks[i][1]) * (N + 1));
        left += blocks[i][1] * (N + 1);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}