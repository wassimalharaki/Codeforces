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

    vi ops;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == t[i]) continue;
        if (t[i] == '1') {
            if (s[0] == '1')
                ops.pb(1), s[0] = '0';
        }
        else {
            if (s[0] == '0')
                ops.pb(1), s[0] = '1';
        }
        ops.pb(i + 1);
        reverse(s.begin(), s.begin() + i + 1);
        for (int j = 0; j < i + 1; j++)
            s[j] = (s[j] == '1' ? '0' : '1');
    }
    cout << ops.size() << " ";
    for (int i = 0; i < ops.size(); i++)
        cout << ops[i] << " ";
    cout nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}