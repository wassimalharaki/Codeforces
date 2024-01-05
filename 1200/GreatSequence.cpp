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
    int n, k; cin >> n >> k;

    map<int, int> map;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        map[a]++;
    }

    int answ = 0;
    for (auto& [key, val] : map) {
        if (val == 0)
            continue;
        if (!map.count(key * k)) {
            answ += val;
            continue;
        }
        int& val2 = map[key * k];
        int sub = min(val, val2);
        val -= sub; val2 -= sub;
        answ += val;
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