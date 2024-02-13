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
    string s; cin >> s;
    string twone = "twone", two = "two", one = "one";
    int n = s.size();

    vi rem;
    for (int i = 0; i < n; i++)
        if (i + 5 <= n and s.substr(i, 5) == twone)
            rem.pb(i + 2), i += 4;
        else if (i + 3 <= n and s.substr(i, 3) == one or s.substr(i, 3) == two)
            rem.pb(i + 1), i += 2;

    cout << rem.size() << nl;
    for (int& a : rem) cout << a + 1 << " ";
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