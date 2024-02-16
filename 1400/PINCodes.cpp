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
    int n; cin >> n;

    v<string> codes(n);
    map<string, int> ok;
    for (string& s : codes) cin >> s, ok[s]++;

    int ans = 0;
    for (string& s : codes) {
        if (ok[s]) {
            ok[s] = 0;
            continue;
        }
        s.back() = char('0' - 1);
        ans++;
        for (int i = 0; i < 10; i++) {
            s.back()++;
            if (not ok.count(s)) {
                ok[s] = 0;
                break;
            }
        }
    }
    cout << ans << nl;
    for (string& s : codes)
        cout << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}