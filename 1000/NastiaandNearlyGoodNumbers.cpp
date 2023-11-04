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
        int a, b; cin >> a >> b;
        b == 1 ?
            cout << "NO" nl:
            b == 2 ?
            cout << "YES" nl
                 << a << " " << 3 * a * (b - 1) << " " << 2 * a * b nl:
            cout << "YES" nl
                 << a << " " << a * (b - 1) << " " << a * b nl;
    }
    return 0;
}