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

        if (n == 1) {
            int a; cin >> a;
            a > 1 ? cout << "NO" nl : cout << "YES" nl;
            continue;
        }

        int max1 = -1, max2 = -1;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a > max1) {
                max2 = max1;
                max1 = a;
            }
            else if (a > max2)
                max2 = a;
        }
        max1 - max2 >= 2 ? cout << "NO" nl : cout << "YES" nl;
    }

    return 0;
}