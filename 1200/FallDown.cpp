#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n, m; cin >> n >> m;

    v<v<char>> grid(n, v<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    bool ok = 1;
    while (ok) {
        ok = 0;
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '*' and grid[i + 1][j] == '.')
                    grid[i][j] = '.', grid[i + 1][j] = '*', ok = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout nl;
    }
    cout nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}