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
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        if (a < x)
            c -= x - a;
        if (c < 0) {
            cout << "NO" nl;
            continue;
        }
        
        if (b < y)
            c -= y - b;
        if (c < 0) {
            cout << "NO" nl;
            continue;
        }

        cout << "YES" nl;
    }

    return 0;
}