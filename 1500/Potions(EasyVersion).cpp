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

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    priority_queue<int, v<int>, greater<int>> pq;
    int hp = 0, ans = 0;
    for (int& a : nums)
        if (a >= 0) {
            ans++;
            hp += a;
        }
        else if (hp + a >= 0) {
            pq.push(a);
            ans++;
            hp += a;
        }
        else if (not pq.empty() and a > pq.top()) {
            hp -= pq.top();
            pq.pop();
            hp += a;
            pq.push(a);
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