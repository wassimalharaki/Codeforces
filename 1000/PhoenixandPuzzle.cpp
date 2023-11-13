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
        int n; cin >> n;
        
        if ((n & 1)) {
            cout << "NO" nl;
            continue;
        }


        int o2 = n / 2;
        int rto2 = (int) sqrt(o2);

        if (rto2 * rto2 == o2) {
            cout << "YES" nl;
            continue;
        }
        rto2++;
        if (rto2 * rto2 == o2) {
            cout << "YES" nl;
            continue;
        }

        if (n % 4) {
            cout << "NO" nl;
            continue;
        }

        int o4 = n / 4;
        int rto4 = (int) sqrt(o4);

        if (rto4 * rto4 == o4) {
            cout << "YES" nl;
            continue;
        }
        rto4++;
        if (rto4 * rto4 == o4) {
            cout << "YES" nl;
            continue;
        }
        cout << "NO" nl;
    }

    return 0;
}