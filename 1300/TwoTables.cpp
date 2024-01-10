#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0);
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
    int room_w, room_h; cin >> room_w >> room_h;
    vi r(4);
    for (int i = 0; i < 4; i++)
        cin >> r[i];
    int w, h; cin >> w >> h;

    int w_sum = w + r[2] - r[0], h_sum = h + r[3] - r[1];
    if (w_sum > room_w and h_sum > room_h) {
        cout << -1 nl;
        return;
    }

    int to_side = min(max(0ll, w - r[0]), max(0ll, w - (room_w - r[2])));
    int to_top = min(max(0ll, h - r[1]), max(0ll, h - (room_h - r[3])));

    if (w_sum <= room_w and h_sum <= room_h)
        cout << min(to_side, to_top) nl;
    else if (w_sum <= room_w)
        cout << to_side nl;
    else
        cout << to_top nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}