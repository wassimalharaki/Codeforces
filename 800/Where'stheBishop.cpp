#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

bool is_valid(int r, int c) {
    return r >= 0 && c >= 0 && r < 8 && c < 8;
}

int32_t main() {
    fast;

    int t; cin >> t;

    while (t--) {
        char board[8][8];

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> board[i][j];

        for (int i = 0; i < 8; i++) {
            bool found = 0;
            for (int j = 0; j < 8; j++)
                if (board[i][j] == '#' 
                        && is_valid(i, j + 2)
                        && board[i][j + 2] == '#') {
                    cout << i + 2 << " " << j + 2 nl;
                    found = 1;
                    break;
                }
            if (found)
                break;
        }
    }

    return 0;
}