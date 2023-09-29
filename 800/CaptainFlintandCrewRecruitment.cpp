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
        
        if (n == 36 || n == 40 || n == 44) {
            cout << "YES" nl << "6 10 15 " << n - 31 nl;
            continue;
        }
        n > 30 ?
            cout << "YES" nl << "6 10 14 " << n - 30 nl:
            cout << "NO" nl;
    }

    return 0;
}