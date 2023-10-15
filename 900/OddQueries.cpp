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

    int T; cin >> T;
    
    while (T--) {
        int n, q; cin >> n >> q;

        vi odd(n + 1);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            odd[i + 1] = odd[i] + (a & 1);
        }
        
        while (q--) {
            int l, r, k; cin >> l >> r >> k;
            l--; r--;

            int subcount = odd[r + 1] - odd[l], totalcount = odd[n];
            k & 1 ? totalcount += (r - l + 1) - subcount : totalcount -= subcount;
            totalcount & 1 ? cout << "YES" nl : cout << "NO" nl;
        }
    }

    return 0;
}