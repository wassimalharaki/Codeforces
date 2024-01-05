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
    int max = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        map[a]++;
        max = std::max(max, map[a]);
    }

    vvi splits(max, vi());
    for (auto& [key, val] : map)
        for (int i = 0; i < val; i++)
            splits[i].pb(key);
        
    int count = 0;
    for (int i = 0; i < max; i++, count++)
        for (int j = 0; j < splits[i].size() - 1; j++)
            if (splits[i][j + 1] - splits[i][j] > 1)
                count++;
    cout << count nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}