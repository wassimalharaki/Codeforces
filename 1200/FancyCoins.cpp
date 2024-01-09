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
    int m, k, a, b;
    cin >> m >> k >> a >> b;

    m -= min(m / k, b) * k;
    m -= min(m, a);

    int fancy = 0, need = k - m % k;
    if (need != k and a >= need)
        m += need;
    fancy += m / k;
    m -= m / k * k;
    fancy += m;
    cout << fancy nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}