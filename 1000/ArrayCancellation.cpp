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

        int avail = 0, coins = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a > 0) {
                avail += a;
                continue;
            }

            int m = min(avail, -a);
            avail -= m;
            coins += -a - m;
        }
        cout << coins nl;
    }

    return 0;
}