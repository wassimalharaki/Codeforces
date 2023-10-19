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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (b >= a)
            cout << b nl;
        else if (d - c >= 0)
            cout << -1 nl;
        else
            cout << b + (a - b + c - d - 1) / (c - d) * c nl;
    }

    return 0;
}