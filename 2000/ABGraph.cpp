#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n, v<int>(n));
    for (auto& x : adj)
        for (int& y : x) {
            char c; cin >> c;
            y = c == '*' ? -1 : c - 'a';
        }

    if (m & 1) {
        cout << "YES" << nl;
        bool alt = 0;
        for (int k = 0; k <= m; k++, alt = !alt)
            cout << (alt ? 1 : 2) << " ";
        cout << nl;
        return;
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j] == adj[j][i] and i != j) {
                cout << "YES" << nl;
                bool alt = 0;
                for (int k = 0; k <= m; k++, alt = !alt)
                    cout << (alt ? i + 1 : j + 1) << " ";
                cout << nl;
                return;
            }

    if (n == 2) {
        cout << "NO" << nl;
        return;
    }

    v<int> cnt(n);
    for (int i = 0; i < n; i++)
        cnt[i] += count(adj[i].begin(), adj[i].end(), 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j and adj[i][j] == 1 and cnt[j]) {
                int k;
                for (k = 0; k < n; k++)
                    if (k != j and adj[j][k])
                        break;

                cout << "YES" << nl;
                int x = m / 2 - 1;
                if (x & 1) {
                    bool alt = 0;
                    for (int y = 0; y <= x; y++, alt = !alt)
                        cout << (alt ? i + 1 : j + 1) << " ";
                    cout << j + 1 << " " << k + 1 << " ";
                    alt = 0;
                    for (int y = 0; y < x; y++, alt = !alt)
                        cout << (alt ? k + 1 : j + 1) << " ";
                    cout << nl;
                }
                else {
                    bool alt = 1;
                    for (int y = 0; y <= x; y++, alt = !alt)
                        cout << (alt ? i + 1 : j + 1) << " ";
                    cout << j + 1 << " " << k + 1 << " ";
                    alt = 0;
                    for (int y = 0; y < x; y++, alt = !alt)
                        cout << (alt ? k + 1 : j + 1) << " ";
                    cout << nl;
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