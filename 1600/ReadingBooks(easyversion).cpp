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
    int n, k; cin >> n >> k;

    int x = 0, y = 0;
    v<int> both, me, you;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        x += b; y += c;
        if (b and c)
            both.push_back(a);
        else if (b)
            me.push_back(a);
        else if (c)
            you.push_back(a);
    }
    sort(all(both)); sort(all(me)); sort(all(you));

    if (x < k or y < k) {
        cout << -1 << nl;
        return;
    }

    priority_queue<int> ok;
    for (int i = 0; i < both.size() and i < k; i++)
        ok.push(both[i]);
    
    int i = 0;
    while (ok.size() < k)
        ok.push(me[i] + you[i++]);
    
    while (i < me.size() and i < you.size()) {
        int x = me[i] + you[i++];
        if (x < ok.top()) {
            ok.pop();
            ok.push(x);
        }
        else break;
    }
    int ans = 0;
    while (ok.size()) {
        ans += ok.top();
        ok.pop();
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