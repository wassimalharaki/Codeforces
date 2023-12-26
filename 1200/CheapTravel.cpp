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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int ones = n * a;
    int mult = n / m;
    int spec = mult * b + min((n - mult * m) * a, b);
    cout << min(ones, spec);
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}