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
    int n; cin >> n;

    vi even, odd;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a & 1 ? odd.pb(i) : even.pb(i);
    }

    if (abs((int) even.size() - (int) odd.size()) > 1) {
        cout << -1 << nl;
        return;
    }

    if (even.size() > odd.size()) {
        int ans = 0, curr = 0;
        for (int i = 0; i < even.size(); i++)
            ans += abs(even[i] - curr), curr += 2;
        cout << ans << nl;
    }
    else if (odd.size() > even.size()) {
        int ans = 0, curr = 0;
        for (int i = 0; i < odd.size(); i++)
            ans += abs(odd[i] - curr), curr += 2;
        cout << ans << nl;
    }
    else {
        int ans1 = 0, ans2 = 0, curr = 0;
        for (int i = 0; i < even.size(); i++) {
            ans1 += abs(odd[i] - curr);
            ans2 += abs(even[i] - curr);
            curr += 2;
        }
        cout << min(ans1, ans2) << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}