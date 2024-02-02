#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

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

int f(int i) {
    return to_string(i).size();
}

void solve() {
    int n; cin >> n;

    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[x]++;
    }

    for (auto& [key, val]: a) {
        if (b.count(key) == 0) continue;
        int min = std::min(val, b[key]);
        b[key] -= min; val -= min;
    }

    int ans = 0;
    for (auto& [key, val]: a)
        if (key >= 10) {
            ans += val;
            a[f(key)] += val;
        }
    for (auto& [key, val]: b)
        if (key >= 10) {
            ans += val;
            b[f(key)] += val;
        }
    
    for (int i = 2; i <= 9; i++)
        ans += abs(a[i] - b[i]);
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