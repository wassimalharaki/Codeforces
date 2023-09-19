#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX

int32_t main() {
    fast

    int t; cin >> t;

    while (t--) {
        int x, y, z; cin >> x >> y >> z;
        int a, b, c;

        if (x < y && z != y) {
            cout << "NO" nl;
        }
        else if (x > y && z != x) {
            cout << "NO" nl;
        }
        else if (x > z && x != y) {
            cout << "NO" nl;
        }
        else if (x < z && z != y) {
            cout << "NO" nl;
        }
        else {
            cout << "YES" nl;
            a = min(x, y);
            b = min(x, z);
            c = min(y, z);
            cout << a << " " << b << " " << c nl;
            
        }
    }

    return 0;
}