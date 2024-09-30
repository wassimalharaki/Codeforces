#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int mex(v<int>& a) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int i = 0; i < (int) a.size(); i++)
        if (a[i] != i)
            return i;
    return a.size();
}

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 2>> a(n);
    int mxm = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        v<int> b(k);
        for (int& x : b) cin >> x;
        a[i][0] = mex(b);
        b.push_back(a[i][0]);
        a[i][1] = mex(b);
        mxm = max(mxm, a[i][1]);
    }
    sort(a.begin(), a.end());

    v<int> cnt(mxm + 1);
    v<v<int>> adj(mxm + 1);
    for (auto& x : a) {
        cnt[x[0]]++;
        adj[x[0]].push_back(x[1]);
    }

    v<int> best(mxm + 1);
    for (int i = mxm; i >= 0; i--) {
        best[i] = i;
        for (int& x : adj[i])
            best[i] = max(best[i], best[x]);
    }

    int ok = a.back()[0];
    for (int i = 0; i <= mxm; i++)
        if (cnt[i] >= 2)
            ok = max(ok, best[i]);

    int ans = 0;
    for (int i = 0; i <= min(m, mxm); i++)
        ans += max(best[i], ok);
        
    if (m > mxm)
        ans += (mxm + 1 + m) * (m - mxm) / 2;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}