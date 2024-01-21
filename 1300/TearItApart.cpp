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

int f(int x) {
    return (x ? 64 - __builtin_clzll(x) : 0);
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    vvi letters(26);
    for (int i = 0; i < n; i++)
        letters[s[i] - 'a'].pb(i);
    cerr << f(0) << nl;
    
    int ans = INF;
    for (int i = 0; i < 26; i++) {
        if (letters[i].empty()) continue;
        int curr = max(f(letters[i][0]), f(n - letters[i].back() - 1));
        for (int j = 1; j < letters[i].size(); j++)
            curr = max(curr, f(letters[i][j] - letters[i][j - 1] - 1));
        ans = min(ans, curr);
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}