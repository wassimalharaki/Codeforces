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
 
        int even = 0;
        vi odds;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (not (a & 1))
                even++;
            else if (a != 1)
                odds.pb(a);
        }

        int tot = (2 * n - even - 1) * even / 2;
        for (int i = 0; i < odds.size(); i++)
            for (int j = i + 1; j < odds.size(); j++)
                tot += gcd(odds[j], odds[i]) > 1;
        cout << tot nl;
    }

    return 0;
}