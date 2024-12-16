#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 2>> a;
    v<int> cnt(m + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= m) {
            a.push_back({x, i + 1});
            cnt[x]++;
        }
    }
    if (a.empty())
        return void(cout << "1 0" << nl);

    for (int i = m; i; i--)
        for (int j = 2 * i; j <= m; j += i)
            cnt[j] += cnt[i];
    int ans = max_element(cnt.begin(), cnt.end()) - cnt.begin();

    v<int> b;
    for (auto& [x, i] : a)
        if (ans % x == 0)
            b.push_back(i);
    
    cout << ans << " " << b.size() << nl;
    for (int& x : b)
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