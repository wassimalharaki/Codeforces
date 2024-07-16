#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int get(int n) {
    int lo = 2, hi = 1.5e9, ans = -1;
    while (lo <= hi) {
        int x = (lo + hi) / 2;
        int val = (2 * x - 1) * (2 * x - 1) - 1;

        if (val < 8 * n)
            ans = x, lo = x + 1;
        else
            hi = x - 1;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    int r = get(n);

    if (!(n & (n - 1)))
        cout << -1 << nl;
    else {
        for (int i = 0; i < 63; i++)
            if ((1ll << i) & n) {
                int x = 1ll << (i + 1);
                cout << (x <= r ? x : n / (x >> 1)) << nl;
                return;
            }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}