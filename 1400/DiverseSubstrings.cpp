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
    string s; cin >> s;
    auto f = [&](int i) -> int {
        return s[i] - '0';
    };

    int ans = 0;
    for (int x = 1; x <= 10; x++) {
        vi counts(10);
        v<deque<int>> last(10);
        auto size = [&]() -> int {
            int a = 0;
            for (int i = 0; i < 10; i++)
                a += counts[i] > 0;
            return a;  
        };
        auto max_occ = [&]() -> int {
            int a = 0;
            for (int i = 0; i < 10; i++)
                a = max(a, counts[i]);
            return a;
        };
        auto min_last = [&]() -> int {
            int a = INF;
            for (int i = 0; i < 10; i++)
                if (not last[i].empty())
                    a = min(a, last[i].back());
            return a;
        };

        int l = 0, r = 0;
        while (1) {
            if (size() < x) {
                if (r == n) break;
                last[f(r)].pb(r);
                counts[f(r++)]++;
                continue;
            }
            if (size() > x) {
                last[f(l)].pop_front();
                counts[f(l++)]--;
                continue;
            }
            if (max_occ() > x) {
                last[f(l)].pop_front();
                counts[f(l++)]--;
                continue;
            }

            ans += min_last() - l + 1;
            if (r == n) break;
            last[f(r)].pb(r);
            counts[f(r++)]++;
        }
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