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

    array<int, 2> cnt{0, 0};
    map<pair<int, int>, int> ratios;
    for (int i = 0; i < n; i++) {
        cnt[s[i] == 'K']++;
        int g = __gcd(cnt[0], cnt[1]);
        cout << ++ratios[{cnt[0] / g, cnt[1] / g}] << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}