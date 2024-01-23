#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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
    int x; cin >> x;

    vi ans{x};
    while (x != 1) {
        int a = (1ll << __builtin_ctzll(x));
        if (a == x) {
            while (x != 1) {
                x >>= 1;
                ans.pb(x);
            }
            break;
        }
        x -= a;
        ans.pb(x);
    }
    cout << ans.size() << nl;
    for (int& i : ans)
        cout << i << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}