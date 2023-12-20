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

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n, m; cin >> n >> m;

        vvi grid(n, vi(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
            
        vi dx{0, 1, 0, -1};
        vi dy{1, 0, -1, 0};

        function valid = [&](int r, int c) -> bool {
            return r >= 0 and c >= 0 and r < n and c < m;
        };

        function bfs = [&](int r, int c) -> int {
            if (grid[r][c] == 0)
                return 0;
                
            queue<pii> unvis;
            unvis.push(mp(r, c));
            int sum = grid[r][c];
            grid[r][c] = 0;

            while (not unvis.empty()) {
                pii front = unvis.front();
                unvis.pop();

                for (int i = 0; i < 4; i++) {
                    r = front.F + dx[i];
                    c = front.S + dy[i];

                    if (not valid(r, c) or grid[r][c] == 0)
                        continue;

                    unvis.push(mp(r, c));
                    sum += grid[r][c];
                    grid[r][c] = 0;
                }
            }
            return sum;
        }; 

        int max = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                max = std::max(bfs(i, j), max);
        cout << max nl;
    }

    return 0;
}