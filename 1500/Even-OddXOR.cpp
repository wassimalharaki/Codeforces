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

    if (n == 3) {
        cout << "2 1 3" << nl;
        return;
    }

    if (n & 1) {
        cout << "0 ";
        n--;
    }

    if (n % 4 == 0)
        for (int i = 2; i < n + 2; i++)
            cout << i << " \n"[i == n + 1];
    else {
        v<int> ans(n);
        iota(all(ans), 2ll);
        ans[n - 1] = (1 << 30) + 1;
        ans[n - 2] = 1;
        ans[n - 4] += 1 << 30;
        for (int& a : ans)
            cout << a << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}