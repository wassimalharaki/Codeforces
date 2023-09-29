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

int32_t main() {
    fast;

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;

        v<v<char>> grid(n, v<char>(n));
        pii p1{-1, -1}, p2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '*') {
                    p1.F == -1 ?
                        p1.F = i, p1.S = j:
                        p2.F = i, p2.S = j;
                }
            }
        
        if (p1.F != p2.F && p1.S != p2.S) {
            grid[p1.F][p2.S] = '*';
            grid[p2.F][p1.S] = '*';
        }
        else if (p1.F == p2.F) {
            if (p1.F >= 1) {
                grid[p1.F - 1][p1.S] = '*';
                grid[p2.F - 1][p2.S] = '*';
            }
            else {
                grid[n - 1][p1.S] = '*';
                grid[n - 1][p2.S] = '*';
            }
        }
        else
            if (p1.S >= 1) {
                grid[p1.F][p1.S - 1] = '*';
                grid[p2.F][p2.S - 1] = '*';
            }
            else {
                grid[p1.F][n - 1] = '*';
                grid[p2.F][n - 1] = '*';
            }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << grid[i][j];
            cout nl;
        }
    }

    return 0;
}