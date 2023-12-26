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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    if (dx and dy and dx != dy) {
        cout << -1;
        return;
    }

    if (dx and dy)
        cout << x1 << " " << y2 << " " << x2 << " " << y1;
    else if (dx)
        cout << x1 << " " << y1 + dx << " " << x2 << " " << y2 + dx;
    else if (dy)
        cout << x1 + dy << " " << y1 << " " << x2 + dy << " " << y2;
    else
        cout << -1;
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}