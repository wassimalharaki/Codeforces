#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, k; cin >> n >> k;

    set<array<int, 2>> ok;
    v<int> a(n);
    set<int> ind;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind.insert(i);
        ok.insert({a[i], i});
    }

    string ans(n, '0');
    bool alt = 0;
    while (ok.size()) {
        auto [_, i] = *ok.rbegin();
        auto it1 = ind.lower_bound(i);
        auto it2 = it1;
        
        int cnt = 0;
        v<set<int>::iterator> del;
        for (; it2 != ind.end() and cnt <= k; cnt++, it2++) {
            int j = *it2;
            ok.erase({a[j], j});
            del.push_back(it2);
            ans[j] = char(int(alt) + 1 + '0'); 
        }

        if (it1 != ind.begin()) {
            it1--, cnt = 0;
            for (; cnt < k; it1--, cnt++) {
                int j = *it1;
                ok.erase({a[j], j});
                del.push_back(it1);
                ans[j] = char(int(alt) + 1 + '0'); 
                if (it1 == ind.begin()) break;
            }
        }

        for (auto& x : del)
            ind.erase(x);
        alt = !alt;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}