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

    v<array<int, 2>> a(n);
    for (auto& p : a)
        cin >> p[0] >> p[1];

    int rem = 0;
    for (auto& p : a) {
        map<array<int, 2>, int> cnt;
        for (auto& q : a) {
            int num = p[1] - q[1];
            int deno = p[0] - q[0];
            int g = gcd(abs(num), abs(deno));
            if (g) num /= g, deno /= g;
            rem += cnt[{num, deno}]++;
        }
    }
    cout << n * (n - 1) * (n - 2) / 6 - rem / 2 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}