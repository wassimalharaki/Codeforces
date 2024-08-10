#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, x; cin >> n >> x;

    priority_queue<int> pq;
    int ans = 0, money = 0;
    for (int i = 0; i < n; i++) {
        int y; cin >> y;

        if (money >= y) {
            ans++;
            pq.push(y);
            money -= y;
        }
        else {
            money -= y;
            pq.push(y);
            money += pq.top();
            pq.pop();
        }
        money += x;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}