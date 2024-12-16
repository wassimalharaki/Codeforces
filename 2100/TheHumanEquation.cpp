#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;

struct node {
    int x, p, i;
    list<ai2>::iterator it;
    node(int _x, int _p, int _i, list<ai2>::iterator _it) {
        x = _x, p = _p, i = _i, it = _it;
    }
    friend bool operator<(const node& n, const node& m) {
        if (n.x == m.x)
            return n.i < m.i;
        return n.x < m.x;
    }
};

void solve() {
    int n; cin >> n;

    int k = 0;
    list<ai2> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (not x) continue;
        if (a.empty() or a.back()[0] * (x < 0 ? -1 : 1) < 0)
            a.push_back({x, k++});
        else
            a.back()[0] += x;
    }
    n = a.size();

    auto get = [&](list<ai2>::iterator it) -> node {
        return {abs((*it)[0]), (*it)[0] < 0 ? -1 : 1, (*it)[1], it};
    };

    multiset<node> ok;
    for (auto it = a.begin(); it != a.end(); it++)
        ok.insert(get(it));

    int ans = 0;
    while (ok.size()) {
        auto [x, p, i, it] = *ok.begin();
        ok.erase(ok.begin());
        ans = x;

        if (it != a.begin() and next(it, 1) != a.end()) {
            auto prv = next(it, -1);
            auto nxt = next(it, 1);
            ok.erase(ok.find(get(prv)));
            ok.erase(ok.find(get(nxt)));
            (*prv)[0] += (*nxt)[0] + p * ans;
            a.erase(nxt);
            ok.insert(get(prv));
        }
        a.erase(it);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}