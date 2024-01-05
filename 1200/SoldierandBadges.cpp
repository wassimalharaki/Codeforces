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

    map<int, int> map;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        map[a]++;
    }

    int answ = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
        int key = it -> F, val = it -> S;
        if (val - 1) {
            answ += val - 1;
            map[key + 1] += val - 1;
        }
    }
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