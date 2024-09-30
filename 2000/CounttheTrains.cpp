#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a) cin >> x;

    set<int> ok;
    ok.insert(0);
    for (int i = 1; i < n; i++)
        if (a[i] < a[*ok.rbegin()])
            ok.insert(i);
    
    while (m--) {
        int i, d; cin >> i >> d;
        a[--i] -= d;
        auto it = --ok.upper_bound(i);

        if (a[*it] > a[i] or *it == i) {
            it++;
            v<int> kill;
            while (it != ok.end() and a[*it] >= a[i])
                kill.push_back(*it++);
            for (int& x : kill)
                ok.erase(x);
            ok.insert(i);
        }
        cout << ok.size() << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}