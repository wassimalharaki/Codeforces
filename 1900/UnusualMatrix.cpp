#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v a(n, v<int>(n)), b(n, v<int>(n));
    for (auto& x : a) {
        string s; cin >> s;
        for (int i = 0; i < n; i++)
            x[i] = s[i] - '0';
    }
    for (auto& x : b) {
        string s; cin >> s;
        for (int i = 0; i < n; i++)
            x[i] = s[i] - '0';
    }

    auto row = [&](int i) -> void {
        for (int j = 0; j < n; j++)
            a[i][j] ^= 1;
    };

    auto col = [&](int j) -> void {
        for (int i = 0; i < n; i++)
            a[i][j] ^= 1;
    };

    for (int j = 0; j < n; j++)
        if (a[0][j] != b[0][j])
            col(j);
    
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j]) {
                row(i);
                break;
            }
    
    cout << (a == b ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}