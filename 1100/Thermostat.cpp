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
        int l, r, x; cin >> l >> r >> x;
        int a, b; cin >> a >> b;

        if (a == b) {
            cout << 0 nl;
            continue;
        }

        if (abs(a - b) >= x) {
            cout << 1 nl;
            continue;
        }

        if (b - l >= x and a - l >= x) {
            cout << 2 nl;
            continue;
        }

        if (r - b >= x and r - a >= x) {
            cout << 2 nl;
            continue;
        }

        if (b + x <= r and r - l >= x and a - l >= x) {
            cout << 3 nl;
            continue;
        }

        if (b - x >= l and r - l >= x and r - a >= x) {
            cout << 3 nl;
            continue;
        }

        cout << -1 nl;
    }

    return 0;
}