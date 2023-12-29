#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

void solve() {
    int n; cin >> n;

    vi p(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> p[i] >> c[i];
    
    bool ok = 1;
    for (int i = 0; i < n; i++)
        if (c[i] > p[i] or (i > 0 and c[i] - c[i - 1] > p[i] - p[i - 1]))
            ok = 0;
    
    cout << (is_sorted(all(p)) and is_sorted(all(c)) and ok ? "YES" : "NO") nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}