#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
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

        int count = 0;
        while (n > 1) {
            int lo = 0, hi = 1e5, rem;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int val = mid * (3 * mid + 1) / 2;  
                if (val <= n)
                    rem = val, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            n -= rem;
            count++;
        }
        cout << count nl;
    }

    return 0;
}