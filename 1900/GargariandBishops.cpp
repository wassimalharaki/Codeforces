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

    v a(n, v<int>(n));
    for (auto& x : a)
        for (auto& y : x)
            cin >> y;

    v<int> tl(2 * n - 1), bl(2 * n - 1);
    for (int k = 0; k < 2 * n - 1; k++) {
        if (k < n) {
            int i = 0, j = k;
            while (j >= 0)
                tl[k] += a[i++][j--];
        }
        else {
            int i = k - n + 1, j = n - 1;
            while (i < n)
                tl[k] += a[i++][j--];
        }
    }

    for (int k = 0; k < 2 * n - 1; k++) {
        if (k < n) {
            int i = n - 1, j = k;
            while (j >= 0)
                bl[k] += a[i--][j--];
        }
        else {
            int i = 2 * (n - 1) - k, j = n - 1;
            while (i >= 0)
                bl[k] += a[i--][j--]; 
        }
    }

    int l = 0, r = 0;
    array<int, 2> x{1, 1}, y{1, 2};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            if ((i ^ j) & 1) {
                int curr = tl[i + j] + bl[n - i - 1 + j] - a[i][j];
                if (curr > r) {
                    y = {i + 1, j + 1};
                    r = curr;
                }
            }
            else {
                int curr = tl[i + j] + bl[n - i - 1 + j] - a[i][j];
                if (curr > l) {
                    x = {i + 1, j + 1};
                    l = curr;
                }
            }
    cout << l + r << nl;
    cout << x[0] << " " << x[1] << " " << y[0] << " " << y[1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}