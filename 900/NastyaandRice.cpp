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
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        int mxw = (a + b) * n, mnw = (a - b) * n;
        int mxr = c + d, mnr = c - d;

        (mnr <= mxw && mxw <= mxr || mnr <= mnw && mnw <= mxr || mnw <= mnr && mxw >= mxr)?
            cout << "YES" nl:
            cout << "NO" nl;
    }

    return 0;
}