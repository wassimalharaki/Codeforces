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

    bool ok = 1;
    for (int& a : nums) if (a > 0) ok = 0;

    if (is_sorted(all(nums))) {
        cout << 0 << nl;
        return;
    }

    vi copy1(nums), copy2(nums);
    vpii forwards, backwards;
    bool f = 1, b = 1;
    {
        for (int i = 1; i < n; i++) {
            if (copy1[i] >= copy1[i - 1])
                 continue;
            int need = copy1[i - 1] - copy1[i];
            int times = INF, a = 0;
            for (int j = 0; j < n; j++) {
                if (copy1[j] <= 0) continue;
                int can = (need + copy1[j] - 1) / copy1[j];
                if (can < times)
                    times = can, a = j;
                else if (can == times and copy1[j] < copy1[a])
                    a = j;
            }
            if (times == INF)
                times = 1, f = 0;
            copy1[i] += times * copy1[a];
            while (times--)
                forwards.pb(mp(i + 1, a + 1));
        }
    }

    {
        for (int i = n - 2; i >= 0; i--) {
            if (copy2[i] <= copy2[i + 1])
                continue;
            int need = copy2[i] - copy2[i + 1];
            int times = INF, a = 0;
            for (int j = 0; j < n; j++) {
                if (copy2[j] >= 0) continue;
                int can = (need - copy2[j] - 1) / -copy2[j];
                if (can < times)
                    times = can, a = j;
                else if (can == times and copy2[j] > copy2[a])
                    a = j;
            }
            if (times == INF)
                times = 1, b = 0;
            copy2[i] += times * copy2[a];
            while (times--)
                backwards.pb(mp(i + 1, a + 1));
        }
    }

    auto fwd = [&]() -> void {
        cout << forwards.size() << nl;
        for (pii& p : forwards)
            cout << p.F << " " << p.S << nl;
    };

    auto bwd = [&]() -> void {
        cout << backwards.size() << nl;
        for (pii& p : backwards)
            cout << p.F << " " << p.S << nl;
    };

    if (f and b)
        forwards.size() < backwards.size() ? fwd() : bwd();
    else if (f)
        fwd();
    else
        bwd();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}