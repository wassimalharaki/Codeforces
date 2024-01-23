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
    string s; cin >> s;

    int k = 0;
    v<bool> ok(n);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) continue;
        if ((i - k) & 1) continue;
        k++;
        ok[i] = 1;
    }
    if ((n - k) & 1) {
        k++;
        for (int i = n - 1; i >= 0; i--)
            if (not ok[i]) {
                ok[i] = 1;
                break;
            }
    }
    cout << k << nl;
    for (int i = 0; i < n; i++)
        if (not ok[i])
            cout << s[i];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}