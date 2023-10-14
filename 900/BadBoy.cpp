#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int t; cin >> t;
    
    while (t--) {
        int n, m, i, j;
        cin >> n >> m >> i >> j;

        auto dist = [&](int dstr, int dstc) -> int {
            return abs(j - dstc) + abs(i - dstr);
        };

        v<pair<int, pii>> dists{{dist(1, 1), {1, 1}}, {dist(1, m), {1, m}}, {dist(n, 1), {n, 1}}, {dist(n, m), {n, m}}};
        sort(all(dists));
        cout << dists[3].S.F << " " << dists[3].S.S << " " 
             << (dists[3].S.F == 1 ? n : 1) << " "
             << (dists[3].S.S == 1 ? m : 1) nl;
    }

    return 0;
}