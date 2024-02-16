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
    string s, t; cin >> s >> t;
 
    vi a(26), b(26);
    for (int i = 0; i < n; i++)
        a[s[i] - 'a']++,
        b[t[i] - 'a']++;
    
    if (a != b) {
        cout << "NO" << nl;
        return;
    }
 
    for (int i = 0; i < n; i++) {
        if (i - 0 >= k) continue;
        if (n - 1 - i >= k) continue;
        if (s[i] != t[i]) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}