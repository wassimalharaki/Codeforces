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

using a3 = array<int, 3>;

void solve() {
    int n; cin >> n;
    v<int> ans(n);

    int i = 1;
    priority_queue<a3> pq;
    pq.push({n, -1, -n});

    while (pq.size()) {
        auto [cnt, l, r] = pq.top();
        pq.pop();
        if (cnt <= 0) continue;
        l = -l, r = -r;
        int x = r - l + 1;
        if (x & 1) {
            int mid = (r + l) / 2;
            ans[mid - 1] = i++;
            pq.push({cnt / 2, -l, -(mid - 1)});
            pq.push({cnt / 2, -(mid + 1), -r});
        }
        else {
            int mid = (r + l - 1) / 2;
            ans[mid - 1] = i++;
            pq.push({cnt / 2 - 1, -l, -(mid - 1)});
            pq.push({cnt / 2, -(mid + 1), -r});
        }
    }

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