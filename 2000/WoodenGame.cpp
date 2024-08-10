#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 20;

void solve() {
    int k; cin >> k;

    int ans = 0;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        for (int j = N - 1; j >= 0; j--) {
            if (!((1 << j) & x)) continue;
            if (ans & (1 << j))
                ans |= (1 << j) - 1;
            else
                ans |= (1 << j);
        }
        for (int j; --x;) cin >> j;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}