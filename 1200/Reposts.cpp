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

    map<string, v<string>> adj;
    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b >> b;
        transform(all(a), a.begin(), ::tolower);
        transform(all(b), b.begin(), ::tolower);
        adj[b].pb(a);
    }

    int answ = 1;
    function<void(string&, int)> dfs = [&](string& src, int h) {
        answ = max(answ, h++);
        for (auto& s : adj[src])
            dfs(s, h);
    };

    string s = "polycarp";
    dfs(s, 1);
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}