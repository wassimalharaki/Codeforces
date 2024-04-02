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
    const int N = n;

    v<int> ans;
    for (int i = 1; i < n; i++)
        if (gcd(i, n) == 1)
            ans.push_back(i);

    int prod = 1;
    for (int& a : ans)
        prod = prod * a % N;
    if (prod != 1) ans.pop_back();
    cout << ans.size() << nl;
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}