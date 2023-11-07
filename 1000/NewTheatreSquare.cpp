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

    int T; cin >> T;
    
    while (T--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        y = min(y, 2 * x);

        v<vi> map(n, vi(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                char c; cin >> c;
                c == '.' ? map[i][j] = 1 : map[i][j] = 0;
            }
        
        int minprice = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int count = 0;
                while (j < m and map[i][j] == 1)
                    count++, j++;
                minprice += count / 2 * y + x * (count & 1);
            }
        cout << minprice nl;
    }

    return 0;
}