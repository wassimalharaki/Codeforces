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

    v<v<int>> nums(n, v<int>(m));
    v<array<int, 2>> bits(n, {INT_MAX, 0});
    for (int i = 0; i < n; i++)
        for (int& a : nums[i]) {
            cin >> a;
            bits[i][0] &= a;
            bits[i][1] |= a;
        }

    for (int x = 0; x < 30; x++) {
        int forced = 0, have = 0;
        for (int i = 0; i < n; i++)
            if (bits[i][0] & (1 << x))
                forced++;
            else if (bits[i][1] & (1 << x))
                have++;
        
        if (forced & 1) {
            cout << "TAK" << nl;
            for (int i = 0; i < n; i++)
                if (bits[i][0] & (1 << x))
                    cout << 1 << " ";
                else {
                    for (int j = 0; j < m; j++)
                        if ((nums[i][j] & (1 << x)) == 0) {
                            cout << j + 1 << " ";
                            break;
                        }
                }
        }
        else {
            if (not have) continue;
            cout << "TAK" << nl;
            bool ok = 0;
            for (int i = 0; i < n; i++)
                if (bits[i][0] & (1 << x))
                    cout << 1 << " ";
                else if (not ok and (bits[i][1] & (1 << x)))
                    for (int j = 0; j < m; j++) {
                        if (nums[i][j] & (1 << x)) {
                            cout << j + 1 << " ";
                            ok = 1;
                            break;
                        }
                    }
                else
                    for (int j = 0; j < m; j++)
                        if ((nums[i][j] & (1 << x)) == 0) {
                            cout << j + 1 << " ";
                            break;
                        }
        }
        return;
    }
    cout << "NIE" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}