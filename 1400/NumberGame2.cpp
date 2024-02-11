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

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));

    auto check = [&](int k) -> bool {
        multiset<int> game;
        for (int& a : nums)
            game.insert(a);
        
        for (int i = 0; i < k; i++) {
            if (game.empty())
                return 0;

            auto it = game.upper_bound(k - i);
            if (it == game.begin())
                return 0;
            --it;

            game.erase(it);
            if (game.empty())
                continue;
            int a = *game.begin();
            a += k - i;
            game.erase(game.begin());
            game.insert(a);
        }
        return 1;
    };
    
    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
    }
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