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
    int n, c; cin >> n >> c;

    v<int> a(c + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    v<int> pref(c + 1);
    partial_sum(a.begin(), a.end(), pref.begin());

    bool ans = a[1] > 0;
    for (int i = 1; i <= c and ans; i++)
        if (a[i])
            for (int j = 2 * i; j <= c and ans; j += i)
                if (pref[min(c, j + i - 1)] - pref[j - 1])
                    ans &= a[j / i] > 0;
    cout << (ans ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}