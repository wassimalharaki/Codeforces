#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 1000;

void solve() {
    int n; cin >> n;

    v<v<array<int, 2>>> a(N + 1);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[x / N].push_back({y, i});
    }
    for (int i = 0; i <= N; i++)
        if (i & 1)
            sort(a[i].begin(), a[i].end());
        else
            sort(a[i].rbegin(), a[i].rend());
    
    v<int> ans;
    for (auto& x : a)
        for (auto& [y, i] : x)
            ans.push_back(i + 1);
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}