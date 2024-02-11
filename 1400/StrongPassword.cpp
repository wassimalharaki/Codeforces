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
    int m; cin >> m;
    string l, r; cin >> l >> r;

    vvi digits(10);
    for (int i = 0; i < s.size(); i++)
        digits[s[i] - '0'].pb(i);

    int prev = -1;
    for (int i = 0; i < m; i++) {
        int max = 0;
        for (char c = l[i]; c <= r[i]; c++) {
            int a = c - '0';
            auto it = upper_bound(all(digits[a]), prev);
            if (it == digits[a].end()) {
                cout << "YES" << nl;
                return;
            }
            max = std::max(max, *it);
        }
        prev = max;
    }
    cout << "NO" << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}