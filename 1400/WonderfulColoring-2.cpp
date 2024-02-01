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
    int n, k; cin >> n >> k;

    unordered_map<int, vi, custom_hash> map;
    vi orig(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        orig[i] = a;
        map[a].pb(i);
    }

    int a = 0;
    vvi nums;
    for (auto& [key, val] : map) {
        a += min(k, (int) val.size());
        nums.pb(val);
    }
    sort(rall(nums), [&](vi& l, vi& r) -> bool {
        return l.size() < r.size();
    });

    int x = a / k, j = 1;
    vi ans(n);
    for (vi& val : nums) {
        if (j > x * k) break;
        for (int i = 0; i < min((int) val.size(), k); i++) {
            ans[val[i]] = (j++ - 1) % k + 1;
            if (j > x * k) break;
        }
    }
    for (int& i : ans)
        cout << i << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}