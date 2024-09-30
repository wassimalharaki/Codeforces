#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using lii = list<int>::iterator;

void solve() {
    int n; cin >> n;

    list<int> a(n);
    for (int& x : a) cin >> x;

    if (*min_element(a.begin(), a.end())) {
        cout << "NO" << nl;
        return;
    }

    auto get = [&](lii& it) -> array<int, 2> {
        array<int, 2> x{INT_MAX, INT_MAX};
        if (it != a.begin())
            x[0] = *next(it, -1);
        if (it != --a.end())
            x[1] = *next(it, 1);
        return x;
    };

    priority_queue<lii, v<lii>, decltype([](auto& l, auto& r) {
        return *l < *r;
    })> pq;
    for (auto it = a.begin(); it != a.end(); it++) {
        auto x = get(it);
        if (*it - x[0] == 1 or *it - x[1] == 1)
            pq.push(it);
    }

    while (pq.size()) {
        auto it = pq.top();
        pq.pop();
        auto x = get(it);
        if (x[0] == x[1] + 1) {
            auto it2 = next(it, -1);
            auto y = get(it2);
            if (*it2 - y[0] != 1)
                pq.push(it2);
        }
        else if (x[1] == x[0] + 1) {
            auto it2 = next(it, 1);
            auto y = get(it2);
            if (*it2 - y[1] != 1)
                pq.push(it2);
        }
        a.erase(it);
    }
    cout << (a.size() == 1 ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}