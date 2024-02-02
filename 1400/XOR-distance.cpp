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
    int a, b, r; cin >> a >> b >> r;
    if (b > a) swap(a, b);
    int x = 0;
    bool abig = 0, bbig = 0, ok = 0;
    for (int i = 63; i >= 0; i--) {
        int c = (1ll << i);
        bool aa = c & a;
        bool bb = c & b;
        if (not ok) {
            if (aa and not bb) {
                abig = 1;
                ok = 1;
            }
            if (bb and not aa) {
                bbig = 1;
                ok = 1;
            }
            continue;
        }
        if (aa ^ bb) {
            if (x + c > r) continue;
            if (bbig) {
                if (bb)
                    x += c;
            }
            else {
                if (aa)
                    x += c;
            }
        }
    }
    cout << abs((a ^ x) - (b ^ x)) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}