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

vector<int> divisors(int n) {
    vector<int> divs;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divs.push_back(i);

    for (int i = divs.size() - 1; i >= 0; i--)
        if (n / divs[i] != divs[i])
            divs.push_back(n / divs[i]);

    return divs;
}

void solve() {
    int a, b; cin >> a >> b;
    v<int> divs = divisors(gcd(a, b));

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        auto it = upper_bound(all(divs), r);
        if (it == divs.begin())
            cout << -1 << nl;
        else
            cout << (*(--it) < l ? -1 : *it) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}