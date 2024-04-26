#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, q; cin >> n >> q;

    v<set<int>> apps(n + 1);
    set<array<int, 2>> notifs;
    int i = 0, curr = 0;

    while (q--) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            notifs.insert({i, x});
            apps[x].insert(i++);
            curr++;
        }
        else if (t == 2) {
            curr -= apps[x].size();
            for (int j : apps[x])
                notifs.erase({j, x});
            apps[x].clear();
        }
        else {
            while (notifs.size()) {
                auto a = *notifs.begin();
                if (a[0] >= x) break;
                curr--;
                apps[a[1]].erase(a[0]);
                notifs.erase(notifs.begin());
            }
        }
        cout << curr << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}