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
    map<int, int> pf;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            pf[i]++;
        }
    }
    if (n != 1) pf[n]++;
    cout << (pf.size() == 1 ? pf.begin() -> first : 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}