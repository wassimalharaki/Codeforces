#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

void solve() {
    int n, m; cin >> n >> m;

    v<v<char>> board(n, v<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    int alt = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            for (int j = m - 1; j >= 0; j--, alt = !alt)
                if (alt)
                    board[i][j] = (board[i][j] == '.' ? 'W' : '-');
                else
                    board[i][j] = (board[i][j] == '.' ? 'B' : '-');
        }
        else {
            for (int j = 0; j < m; j++, alt = !alt)
                if (alt)
                    board[i][j] = (board[i][j] == '.' ? 'W' : '-');
                else
                    board[i][j] = (board[i][j] == '.' ? 'B' : '-');
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << board[i][j];
        cout nl;
    }
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}