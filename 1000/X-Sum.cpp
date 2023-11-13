#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n, m; cin >> n >> m;

        v<vi> board(n, vi(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];

        vi up(n + m - 1), down(n + m - 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                up[i + j] += board[i][j];
                down[(n - i - 1) + j] += board[i][j];
            }

        int answ = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                answ = max(answ, up[i + j] + down[(n - i - 1) + j] - board[i][j]);
        cout << answ nl;
    }

    return 0;
}