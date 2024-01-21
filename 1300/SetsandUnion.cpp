#include <bits/stdc++.h>

using namespace std;

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
    int n; cin >> n;

    vvi nums(51);
    unordered_set<int, custom_hash> onion;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int a; cin >> a;
            nums[a].pb(i);
            onion.insert(a);
        }
    }

    int max = 0;
    for (auto& exc : onion) {
        unordered_set<int, custom_hash> curr;
        for (int i = 1; i < 51; i++) {
            if (i == exc) continue;
            for (int j = 0; j < nums[i].size(); j++)
                if (not binary_search(all(nums[exc]), nums[i][j])) {
                    curr.insert(i);
                    break;
                }
        }
        max = std::max((int) curr.size(), max);
    }
    cout << max << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}