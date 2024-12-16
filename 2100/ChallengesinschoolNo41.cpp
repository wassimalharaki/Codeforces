#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    auto valid = [&](int i) -> bool {
        return i >= 0 and i + 1 < n
            and s[i] == 'R' and s[i + 1] == 'L';
    };
    
    int curr = 0, cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'R')
            cnt++;
        else
            curr += cnt;

    v<int> use;
    for (int i = 0; i < n - 1; i++)
        if (valid(i)) use.push_back(i);

    v<v<int>> ans(k);
    for (int i = 0; i < k; i++) {
        int need = min((int) use.size(), curr - (k - i - 1));
        if (need <= 0) return void(cout << -1 << nl);

        v<int> next;
        for (int j = (int) use.size() - 1; need; j--, need--, curr--) {
            ans[i].push_back(use[j] + 1);
            swap(s[use[j]], s[use[j] + 1]);
            if (valid(use[j] + 1))
                next.push_back(use[j] + 1);
            if (valid(use[j] - 1))
                next.push_back(use[j] - 1);
            use.pop_back();
        }
        for (int& j : next)
            use.push_back(j);
    }
    if (curr) return void(cout << -1 << nl);

    for (auto& x : ans) {
        cout << x.size() << " ";
        for (int& y : x)
            cout << y << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}