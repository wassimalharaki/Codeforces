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
        int x, n, m; cin >> x >> n >> m;

        while (x > 20 && n > 0)
            x = x / 2 + 10, n--;
        x - 10 * m <= 0 ? cout << "YES" nl : cout << "NO" nl;
    }

    return 0;
}