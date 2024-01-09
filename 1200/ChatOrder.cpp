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

    unordered_set<string> set;
    stack<string> s;
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        s.push(t);
        set.insert(t);
    }

    while (not s.empty()) {
        if (set.count(s.top()))
            cout << s.top() nl;
        set.erase(s.top());
        s.pop();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}