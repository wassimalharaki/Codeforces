#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<int> ops;
    int bigbit = -1;
    bool start = 0;
    for (int i = 63; i >= 0; i--) {
        bool x_bit = ((1ll << i) & n) > 0;
        bool y_bit = ((1ll << i) & m) > 0;
        if (x_bit and bigbit == -1 and y_bit) {
            cout << 1 << nl;
            cout << n << " " << m << nl;
            return;
        }
        if (x_bit == y_bit) continue;

        int num = 0;
        bool ok = 0;
        for (int j = i - 1; j >= 0; j--) {
            x_bit = ((1ll << j) & n) > 0;
            y_bit = ((1ll << j) & m) > 0;
            if (x_bit and y_bit and not ok) {
                cout << 1 << nl;
                cout << n << " " << m << nl;
                return;
            }

            if (x_bit == y_bit) continue;
            if (y_bit and not x_bit) {
                if (not ok) {
                    cout << -1 << nl;
                    return;
                }
                num += (1ll << j);
            }
            else {
                ok = 1;
                num += (1ll << j);
            }
        }
        if (num == 0) {
            cout << 1 << nl;
            cout << n << " " << m << nl;
        }
        else {
            cout << 2 << nl;
            cout << n << " " << (n ^= num) << " " << (n ^= (1ll << i)) << nl;
        }
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}