#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        if (l == -1) l = i;
        r = i;
    }

    if (l == -1) {
        cout << 0 << nl;
        return;
    }

    int a = n - 1 - r;
    if (a + l <= k) {
        rotate(s.begin() + r, s.begin() + r + 1, s.end());
        if (l != r)
            rotate(s.begin(), s.begin() + l, s.begin() + l + 1);
    }
    else if (a <= k)
        rotate(s.begin() + r, s.begin() + r + 1, s.end());
    else if (l <= k)
        rotate(s.begin(), s.begin() + l, s.begin() + l + 1);


    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += stoll(string{s[i], s[i + 1]});
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}