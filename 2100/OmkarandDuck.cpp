#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v a(n, v<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (((j & 1) ^ 1))
                a[i][j] = 1ll << (i + j);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        v<array<int, 2>> ans;
        int i = n - 1, j = n - 1;
        while (k) {
            int x = 1ll << __lg(k);
            if (x == a[i][j]) {
                k -= a[i][j];
                ans.push_back({i + 1, j + 1});
            }
            else if (a[i][j]) {
                if (i and a[i - 1][j] == x)
                    i--;
                else
                    j--;
            }
            else {
                ans.push_back({i + 1, j + 1});
                if (a[i][j - 1] == x)
                    j--;
                else
                    i--;
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto& [x, y] : ans)
            cout << x << " " << y << endl;
    }
}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--) solve();
}