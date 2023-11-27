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

        int lo = 0, hi = 1e9;
        int answ = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (mid * mid >= n)
                answ = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        cout << answ - 1 nl;
    }

    return 0;
}