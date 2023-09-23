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
        int a; cin >> a;

        int epar = a & 1;
        cin >> a;
        int opar = a & 1;

        bool evens = true, odds = true;
        for (int i = 2; i < n; i++) {
            cin >> a;
            if (i & 1) {
                if ((a ^ opar) & 1)
                    odds = false;
            }
            else if ((a ^ epar) & 1)
                evens = false;
        }
        evens && odds ? cout << "YES" nl : cout << "NO" nl;
    }

    return 0;
}