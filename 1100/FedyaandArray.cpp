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

void solve() {
    int x, y; cin >> x >> y;

    if (x - y == 1) {
        cout << 2 nl;
        cout << x << " " << y nl;
        return;
    }

    cout << (x - y) * 2 nl;
    cout << x - 1 << " " << x << " " << x - 1 << " ";
    int curr = x - 2;
    while (curr != y)
        cout << curr-- << " ";
    cout << curr++ << " ";
    while (curr != x - 1)
        cout << curr++ << " ";
    cout nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;

    while (T--)
        solve();

    return 0;
}