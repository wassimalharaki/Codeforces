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

const int N = 26;

void solve() {
    array<int, N> val;
    for (int& x : val) cin >> x;
    string s; cin >> s;
    int n = s.size();

    int ans = 0;
    for (char i = 'a'; i <= 'z'; i++) {
        map<int, int> a;
        int curr = 0, j = s.find(i);
        if (j == -1) continue;

        for (; j < n; j++)
            if (s[j] == i) {
                ans += a[curr];
                a[curr += val[i - 'a']]++;
            }
            else
                curr += val[s[j] - 'a'];
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}