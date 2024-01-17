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
    int a, b; cin >> a >> b;
    string s; cin >> s;
    int n = s.size();

    string t{s[0]};
    for (int i = 1; i < n; i++)
        if (s[i] == '0') t.pb('0');
        else if (t.back() != '1') t.pb('1');

    vi prep;
    for (int i = 0; i < t.size(); i++)
        if (t[i] == '1')
            prep.pb(i + 1);
    
    if (prep.empty()) {
        cout << 0 nl;
        return;
    }
    
    int ans = 0, curr = 0;
    for (int i = 0; i < prep.size() - 1; i++) {
        int diff = prep[i + 1] - prep[i] - 1;
        if (2 * a < a + diff * b)
            ans += a + curr, curr = 0;
        else
            curr += diff * b;
    }
    cout << ans + a + curr nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}