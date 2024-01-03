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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    unordered_map<int, int, custom_hash> map;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        map[a % m]++;
    }

    int answ = map.count(0);
    for (auto& [key, val] : map) {
        if (key == 0 or val == 0)
            continue;
        
        if (map.count(m - key) == 0) {
            answ += val;
            val = 0;
            continue;
        }
        
        int sub = min(val, map[m - key]);
        val -= sub; map[m - key] -= sub;
        answ += max(0ll, val + map[m - key] - 1) + 1;
        val = 0, map[m - key] = 0;
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