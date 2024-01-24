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
    int n, k; cin >> n >> k;

    vi nums(n);
    unordered_set<int, custom_hash> sette;
    for (int& a : nums) cin >> a, sette.insert(a);

    if (sette.size() > k) {
        cout << -1 << nl;
        return;
    }

    vi ans;
    while (ans.size() != k)
        for (int i : sette) {
            if (ans.size() == k)
                break;
            ans.pb(i);
        }
    
    while (ans.size() < 1e4)
        ans.pb(ans[ans.size() - k]);
    
    cout << ans.size() << nl;
    for (int& a : ans)
        cout << a << " ";
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