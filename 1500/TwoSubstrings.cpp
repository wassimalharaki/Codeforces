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
    int n = s.size();

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n - 1; i++) {
        string x, y = s.substr(i, 2);
        if (i + 2 < n) x = s.substr(i, 3);
        if (x == "ABA" or x == "BAB")
            c++, i += 2;
        else if (y == "AB")
            a++, i++;
        else if (y == "BA")
            b++, i++;
    }
    cout << ((a > 0) + (b > 0) + c > 1 ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}