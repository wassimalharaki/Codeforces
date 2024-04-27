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
    int n; cin >> n;

    v<int> want(n);
    for (int& a : want) cin >> a;

    set<int> have;
    for (int i = 1; i <= n; i++)
        have.insert(i);

    v<int> ans(n);
    for (int i = 0; i < n; i++)
        if (have.count(want[i])) {
            ans[i] = want[i];
            have.erase(want[i]);
        }
    
    v<int> bad;
    for (int i = 0; i < n; i++)
        if (ans[i] == 0) {
            ans[i] = *have.begin();
            if (ans[i] == i + 1)
                bad.push_back(i);
            have.erase(have.begin());
        }

    while (bad.size() > 1) {
        int i = bad.end()[-1], j = bad.end()[-2];
        swap(ans[i], ans[j]);
        bad.pop_back(); bad.pop_back();
    }

    if (bad.size() == 1) {
        int j;
        for (int i = 0; i < n; i++)
            if (ans[i] == want[bad[0]]) {
                j = i;
                break;
            }
        swap(ans[bad[0]], ans[j]);
    }
    
    int k = 0;
    for (int i = 0; i < n; i++)
        k += ans[i] == want[i];

    cout << k << nl;
    for (int& a : ans)
        cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}