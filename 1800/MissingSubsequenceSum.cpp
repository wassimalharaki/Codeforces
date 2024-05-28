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
    int n, k; cin >> n >> k;

    int msb = 63 - __builtin_clzll(k);
    v<int> bits;
    for (int i = 0; i < 25; i++)
        if ((1 << i) & k)
            bits.push_back(i);
    if (msb == 0) {
        cout << 25 << nl << 3 << " ";
        for (int i = 1; i < 25; i++)
            cout << (1 << i) << " ";
        cout << nl;
    }
    else if (popcount((unsigned int) k) == 1) {
        v<int> ans;
        for (int i = 0; i < 24; i++)
            if (i == msb) {
                int next;
                ans.push_back((1 << (i + 1)) + (1 << i));
                ans.push_back((1 << i) + 1);
            }
            else
                ans.push_back(1 << i);
        
        cout << ans.size() << nl;
        for (int& a : ans)
            cout << a << " ";
        cout << nl;
    }
    else {
        v<int> ans;
        for (int i = 0; i < 23; i++)
            if (i == msb) {
                ans.push_back(k - (1 << i));
                ans.push_back((1 << i) + k);
                ans.push_back(k + 1);
            }
            else
                ans.push_back(1 << i);

        cout << ans.size() << nl;
        for (int& a : ans)
            cout << a << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}