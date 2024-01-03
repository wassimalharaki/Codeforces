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
    
    vi occ;
    for (int i = 0; i < n;) {
        int c = 0;
        occ.pb(1);
        while (++i < n and s[i] == s[i - 1])
            occ[occ.size() - 1]++;
    }

    int answ = n * (n + 1) / 2, sum = 0;
    for (int i = 0; i < occ.size(); i++) {
        if (occ[i] > 1)
            answ -= occ[i] * (occ[i] - 1) / 2 + (occ[i] - 1) * sum;
        sum += occ[i];
    }
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}