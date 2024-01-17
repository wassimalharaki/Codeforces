#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int a, b, c; cin >> a >> b >> c;

    int diff = max(0ll, b - a);
    int sub = min(diff, c);
    a += sub, c -= sub;
    if (a <= b)
        cout << (c + 1) / 2 nl;
    else
        cout << min((c + a - b - 1) / 2, c) + 1 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}