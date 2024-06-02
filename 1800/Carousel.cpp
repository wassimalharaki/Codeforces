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

    v<int> a(n), ans(n);
    for (int& x : a) cin >> x;

    for (int i = 1; i < n; i++)
        ans[i] = (a[i] == a[i - 1] ? ans[i - 1] : !ans[i - 1]);
    
    if (a.back() != a.front() and ans.back() == ans.front()) {
        bool ok = 0;
        for (int i = 0; i < n - 1; i++)
            ok |= ans[i] == ans[i + 1];
        if (not ok)
            ans.back() = 2;
        else {
            for (int i = 0; i < n - 1; i++)
                if (a[i] == a[i + 1]) {
                    ans[i + 1] = !ans[i];
                    for (int j = i + 2; j < n; j++)
                        ans[j] = (a[j] == a[j - 1] ? ans[j - 1] : !ans[j - 1]);
                    break;
                }
        }
    }

    cout << *max_element(ans.begin(), ans.end()) + 1 << nl;
    for (int& x : ans)
        cout << x + 1 << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}