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
        int x, n; cin >> x >> n;
        int add = (n / 2 & 1);
        if (n & 1)
            n / 2 & 1 ? add += n : add -= n;
        x & 1 ? cout << x - add nl : cout << x + add nl;
    }

    return 0;
}