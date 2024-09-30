#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(n), O(log(n))
template <class T>
struct BIT {
    int n;
    vector<T> d;

    BIT(int _n) {
        n = _n;
        d.resize(_n);
    }

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += d[r - 1];
            r -= r & -r;
        }
        return s;
    }

    void add(int p, T x) {
        p++;
        while (p <= n) {
            d[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size();

    int q; cin >> q;
    v<int> ans(q);
    v<v<array<int, 2>>> rb(n);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        rb[--r].push_back({--l, i});
    }

    BIT<int> bit(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            st.push(i);
        else if (st.size()) {
            bit.add(st.top(), 2);
            st.pop();
        }

        for (auto& [l, j] : rb[i])
            ans[j] = bit.sum(l, i + 1);
    }

    for (int& x : ans)
        cout << x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}