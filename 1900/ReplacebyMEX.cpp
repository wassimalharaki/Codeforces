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

    v<int> a(n), cnt(n + 1);
    for (int& x : a) cin >> x;

    auto get = [&]() {
        fill(cnt.begin(), cnt.end(), 0ll);
        int mex = 0;
        for (int& x : a) {
            cnt[x]++;
            while (cnt[mex]) mex++;
        }
        return mex;
    };

    v<int> ans;
    
    while (not is_sorted(a.begin(), a.end())) {
        int mex = get();
        if (mex == n) {
            for (int i = 0; i < n; i++)
                if (a[i] != i) {
                    ans.push_back(i + 1);
                    a[i] = mex;
                    break;
                }
        }
        else {
            a[mex] = mex;
            ans.push_back(mex + 1);
        }
    }

    cout << ans.size() << nl;
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}