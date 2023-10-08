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
        int n, x; cin >> n;

        for (int k = 2; (1 << k) - 1 <= n; k++) {
            double check = (double) n / ((1 << k) - 1);
            if (check == (int) check) {
                x = (int) check;
                break;
            }
        }
        cout << x nl;
    }

    return 0;
}