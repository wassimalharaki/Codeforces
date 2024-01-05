#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
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
    string s, t; cin >> s >> t;

    vpii count(n + 1);
    for (int i = 0; i < n; i++) {
        count[i + 1].F = count[i].F + (s[i] == '1');
        count[i + 1].S = count[i].S + (s[i] == '0');
    }

    bool alt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (alt)
            s[i] == '1' ? s[i] = '0': s[i] = '1';
        if (s[i] == t[i])
            continue;
        if (count[i + 1].F != count[i + 1].S) {
            cout << "NO" nl;
            return;
        }
        alt = !alt;
    }
    cout << "YES" nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}