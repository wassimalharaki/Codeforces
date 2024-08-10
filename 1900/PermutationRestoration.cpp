#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

bool valid(v<int>& a, v<int>& b) {
    int n = a.size();

    set<int> s(a.begin(), a.end());
    if (*s.begin() < 1) return 0;
    if (*s.rbegin() > n) return 0;
    if ((int) s.size() != n) return 0;

    for (int i = 0; i < n; i++)
        if ((i + 1) / a[i] != b[i])
            return 0;
    return 1;
}

using ai2 = array<int, 2>;

void solve() {
    int n; cin >> n;

    v<int> b(n);
    for (int& x : b) cin >> x;

    v<int> a(n);
    v<v<ai2>> ranges(n + 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        if (b[i] == 0)
            l = i + 2,
            r = n;
        else
            l = (i + 1) / (b[i] + 1) + 1,
            r = (i + 1) / b[i];
        ranges[l].push_back({r, i});
    }

    priority_queue<ai2, v<ai2>, greater<ai2>> pq;
    for (int i = 1; i <= n; i++) {
        while (ranges[i].size()) {
            pq.push(ranges[i].back());
            ranges[i].pop_back();
        }
        a[pq.top()[1]] = i;
        pq.pop();
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}