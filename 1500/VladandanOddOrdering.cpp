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

int f(int n, int k, int a = 0) {
    while (k > (n + 1) / 2) {
        k -= (n + 1) / 2;
        n >>= 1;
        a++;
    }
    return (1 << a) + (1 << (a + 1)) * (k - 1);
}
 
void solve() {
    int n, k; cin >> n >> k;
    cout << f(n, k) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}