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
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;

        if (sx - d <= 1 and sx + d >= n) {
            cout << -1 nl;
            continue;
        }

        if (sy - d <= 1 and sy + d >= m) {
            cout << -1 nl;
            continue;
        }

        if (sx - d <= 1 and sy - d <= 1) {
            cout << -1 nl;
            continue;
        }

        if (sx + d >= n and sy + d >= m) {
            cout << -1 nl;
            continue;
        }

        if (n - sx + m - sy <= d) {
            cout << -1 nl;
            continue;
        }

        cout << n - 1 + m - 1 nl;
    }

    return 0;
}