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
    v<v<char>> board(3, v<char>(3));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];
        
    for (int i = 0; i < 3; i++)
        if (board[i][0] != '.' and board[i][0] == board[i][1] and board[i][1] == board[i][2]) {
            cout << board[i][0] nl;
            return;
        }
    
    for (int j = 0; j < 3; j++)
        if (board[0][j] != '.' and board[0][j] == board[1][j] and board[1][j] == board[2][j]) {
            cout << board[0][j] nl;
            return;
        }
    
    if (board[0][0] != '.' and board[0][0] == board[1][1] and board[1][1] == board[2][2]) {
        cout << board[0][0] nl;
        return;
    }

    if (board[0][2] != '.' and board[0][2] == board[1][1] and board[1][1] == board[2][0]) {
        cout << board[0][2] nl;
        return;
    }

    cout << "DRAW" nl;
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        solve();
    }

    return 0;
}