#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;
    
    v<int> a(n), b(n);
    int curr = 1, x = 1, j = 0;
    for (int i = 0; i < (n + k - 1) / k; i++) {
        int lim = min(n, j + k);

        int sz = min(k, lim - j);
        v<int> c(sz);
        for (int& y : c) y = x++;
        reverse(c.begin(), c.end());
        rotate(c.begin(), c.begin() + sz / 2, c.end());

        for (int l = 0; j < lim; j++, l++) {
            a[j] = c[l];
            b[j] = curr;
        }
        curr++;
    }

    for (int& y : a)
        cout << y << " ";
    cout << nl << curr - 1 << nl;
    for (int& y : b)
        cout << y << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}