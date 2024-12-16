#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

bool valid(v<v<int>>& a) {
    int n = a.size();
    for (int r1 = 0; r1 < n; r1++)
        for (int r2 = r1 + 1; r2 < n; r2++)
            for (int c1 = 0; c1 < n; c1++)
                for (int c2 = c1 + 1; c2 < n; c2++)
                    if ((a[r1][c1] + a[r2][c2]) % n == (a[r1][c2] + a[r2][c1]) % n)
                        return 0;
    return 1;
}

void solve() {
    int n; cin >> n;

    v a(n, v<int>(n));
    for (int i = 0; i < n; i++)
        cin >> a[i][i];
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            a[i][(i + j) % n] = (a[i][(i + j - 1) % n] + i + 1) % n;

    for (auto& x : a) {
        for (int& y : x)
            cout << y << " ";
        cout << nl;
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}