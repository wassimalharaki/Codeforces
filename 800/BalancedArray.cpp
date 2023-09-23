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

        if ((n / 2) & 1)
            cout << "NO" nl;
        else {
            cout << "YES" nl;

            int se = 0, so = 0;
            for (int i = 2; i <= n; i += 2) {
                cout << i << " ";
                se += i;
            }
            for (int i = 1; i < n - 2; i += 2) {
                cout << i << " ";
                so += i;
            }
            
            cout << (se - so) nl;
        }
    }

    return 0;
}