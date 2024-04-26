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

    v<int> pos, neg;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a > 0 ? pos.push_back(a) : neg.push_back(a);
    }

    if (pos.empty()) {
        cout << "No" << nl;
        return;
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    int x = pos[0] - neg[0];

    v<int> ans;
    int i = 0, j = 0, sum = 0;
    while (i < pos.size() and j < neg.size())
        if (sum + pos[i] >= x) {
            sum = max(sum + neg[j], 0ll);
            ans.push_back(neg[j++]);
        }
        else {
            sum += pos[i];
            ans.push_back(pos[i++]);
        }

    while (i < pos.size())
        ans.push_back(pos[i++]);
    while (j < neg.size())
        ans.push_back(neg[j++]);

    cout << "Yes" << nl;
    for (int& a : ans)
        cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    int T = 1;
    cin >> T;
    while (T--) solve();
}