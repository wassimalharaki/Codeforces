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
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
 
    vi block(k);
    int a = 0;
    string t;
    for (int i = 0; i < m; i++) {
        block[s[i] - 'a']++;
        if (*min_element(all(block)) == 1) {
            t.pb(s[i]);
            a++;
            fill(all(block), 0ll);
        }
    }
    if (a >= n)
        cout << "YES" << nl;
    else {
        cout << "NO" << nl;
        for (int i = 0; i < k; i++) {
            if (block[i] == 0) {
                while (t.size() < n)
                    t.pb(char(i + 'a'));
                break;
            }
        }
        cout << t << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}