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
    string s; cin >> s;
    int m; cin >> m;
    int n = s.size();

    v<int> ans;
    auto f = [&](int i, int l, int r, int prev, auto&& f) -> bool {
        if (i == m) return 1;
        if (i & 1) {
            for (int j = n - 1; j >= 0; j--)
                if (s[j] == '1' and j != prev and r + j + 1 > l) {
                    ans.push_back(j + 1);
                    if (f(i + 1, l, r + j + 1, j, f))
                        return 1;
                    ans.pop_back();
                }
        }
        else {
            for (int j = n - 1; j >= 0; j--)
                if (s[j] == '1' and j != prev and l + j + 1 > r) {
                    ans.push_back(j + 1);
                    if (f(i + 1, l + j + 1, r, j, f))
                        return 1;
                    ans.pop_back();
                }
        }
        return 0;
    };

    if (!f(0, 0, 0, -1, f))
        cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        for (int& a : ans)
            cout << a << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}