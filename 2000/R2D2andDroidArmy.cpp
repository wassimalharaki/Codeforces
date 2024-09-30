#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v a(n, v<int>(m));
    for (auto& x : a)
        for (int& y : x)
            cin >> y;
    
    auto add = [&](int x, map<int, int>& mp) {
        mp[x]++;
    };

    auto rem = [&](int x, map<int, int>& mp) {
        if (--mp[x] == 0) mp.erase(x);
    };

    auto get = [&](map<int, int>& mp) {
        if (mp.empty()) return 0ll;
        return mp.rbegin() -> first;
    };
    
    v<int> ans(m);
    v<map<int, int>> cnt(m);
    int best = 0, curr = 0;
    int l = 0, r = 0;
    while (r < n) {
        for (int i = 0; i < m; i++) {
            curr -= get(cnt[i]);
            add(a[r][i], cnt[i]);
            curr += get(cnt[i]);
        }
        r++;
        
        while (curr > k) {
            for (int i = 0; i < m; i++) {
                curr -= get(cnt[i]);
                rem(a[l][i], cnt[i]);
                curr += get(cnt[i]);
            }
            l++;
        }

        if (r - l > best) {
            best = r - l;
            for (int i = 0; i < m; i++)
                ans[i] = get(cnt[i]);
        }
    }

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