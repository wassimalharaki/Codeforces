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
        int a, b, c; cin >> a >> b >> c;
        int mx = max(a, max(b, c));
        
        int tie = 0;
        if (a == b && a == mx || a == c && a == mx || b == c && b == mx)
            tie = 1;

        int A = (mx - a)? mx - a + 1 : tie;
        int B = (mx - b)? mx - b + 1 : tie;
        int C = (mx - c)? mx - c + 1 : tie;

        cout << A << " " << B << " " << C nl;
    }

    return 0;
}