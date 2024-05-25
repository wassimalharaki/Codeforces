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

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    v<int> a{1};
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1])
            a.back()++;
        else
            a.push_back(1);

    if (a.size() != 1 and s[0] == s[n - 1]) {
        a.front() += a.back();
        a.pop_back();
    }

    int ans = 0;
    if (a.size() == 1)
        ans = (a[0] + 2) / 3;
    else
        for (int& x : a)
            ans += x / 3;

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}