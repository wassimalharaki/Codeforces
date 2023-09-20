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
#define F first
#define S second

int32_t main() {
    fast

    int t; cin >> t;

    while (t--) {
        int x; cin >> x;
        vi keys(3); cin >> keys[0] >> keys[1] >> keys[2];


        x = keys[x - 1];
        if (x) {
            x = keys[x - 1];
            if (x)
                cout << "YES" nl;
            else
                cout << "NO" nl;
        }
        else
            cout << "NO" nl;

    }

    return 0;
}