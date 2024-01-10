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
    string s; cin >> s;

    if (n & 1) {
        cout << - 1 nl;
        return;
    }

    int ones = count(all(s), '1');
    int zeroes = count(all(s), '0');
    if (ones != zeroes) {
        cout << -1 nl;
        return;
    }

    vi ops;
    int l = 0, r = n;
    while (l <= r) {
        if (s[l] == s[r - 1]) {
            if (s[l] == '0') {
                s = s.substr(0, r) + "01" + s.substr(r, s.size() - r);
                ops.pb(r);
            }
            else {
                s = s.substr(0, l) + "01" + s.substr(l, s.size() - l);
                ops.pb(l);
            }
            r += 2;
        }
        l++, r--;
    }

    cout << ops.size() nl;
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