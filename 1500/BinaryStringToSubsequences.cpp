#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    stack<int> need_zeroes, need_ones;
    int k = 0;
    v<int> ans(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == '1') {
            if (need_ones.empty()) {
                need_zeroes.push(++k);
                ans[i] = k;
            }
            else {
                int j = need_ones.top();
                need_ones.pop();
                ans[i] = j;
                need_zeroes.push(j);
            }
        }
        else {
            if (need_zeroes.empty()) {
                need_ones.push(++k);
                ans[i] = k;
            }
            else {
                int j = need_zeroes.top();
                need_zeroes.pop();
                ans[i] = j;
                need_ones.push(j);
            }
        }
    }
    cout << k << nl;
    for (int& a : ans) cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}