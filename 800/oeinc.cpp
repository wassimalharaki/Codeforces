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
        int n; cin >> n;

        bool evens = true, odds = true;
        int epar = -1, opar = -1;
        int a; cin >> a;
        epar = a % 2;
        cin >> a;
        opar = a % 2;

        for (int i = 2; i < n; i++) {
            int a; cin >> a;
            if (i % 2 == 0) {
                if (a % 2 != epar)
                    evens = false;
            }
            else {
                if (a % 2 != opar)
                    odds = false;
            }
        }

        if (evens && odds)
            cout << "YES" nl;
        else
            cout << "NO" nl;
    }

    return 0;
}