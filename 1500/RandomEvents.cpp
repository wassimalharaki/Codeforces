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
    int n, m; cin >> n >> m;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int look = 0;
    for (int i = n - 1; i >= 0; i--)
        if (nums[i] != i + 1) {
            look = i + 1; break;
        }
    
    double x = 1;
    for (int i = 0; i < m; i++) {
        int r; cin >> r;
        double p; cin >> p;
        if (r < look) continue;
        x *= 1 - p;
    }
    cout << (look == 0 ? 1. : 1 - x) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(6);
    int T = 1;
    cin >> T;
    while (T--) solve();
}