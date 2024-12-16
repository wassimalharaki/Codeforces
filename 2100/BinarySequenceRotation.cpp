#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    if (count(s.begin(), s.end(), '1') != count(t.begin(), t.end(), '1')) {
        cout << -1 << nl;
        return;
    }

    array<set<int>, 2> a;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
            a[s[i] - '0'].insert(i);
    
    int ans = 0;
    while (1) {
        if (a[0].empty()) {
            ans += a[1].size();
            break;
        }
        if (a[1].empty()) {
            ans += a[0].size();
            break;
        }
        ans++;

        bool prev = *a[0].begin() > *a[1].begin();
        int i = prev ? *a[1].begin() : *a[0].begin();
        array<v<int>, 2> kill;
        while (1) {
            kill[prev].push_back(i);
            prev = !prev;
            auto it = a[prev].lower_bound(i);
            if (it == a[prev].end()) break;
            i = *it;
        }
        for (int j = 0; j < 2; j++)
            for (int& k : kill[j])
                a[j].erase(k);
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