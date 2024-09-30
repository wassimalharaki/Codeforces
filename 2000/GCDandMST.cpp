#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return gcd(a, b);
}

int e() {
    return 0;
}

// O(nlog(n)), O(1)
template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
    vector<vector<S>> d;

    sparse_table(vector<S>& a) {
        int n = a.size(), k = 1 + __lg(n);
        d.resize(k, vector<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        if (l == r) return e();
        int i = __lg(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

// O(n), O(1)
struct DSU {
    vector<int> p;

    DSU(int n) { p.resize(n, -1); }

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    int size(int x) { return - p[find(x)]; }

    bool same_set(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        return true;
    }
};

void solve() {
    int n, p; cin >> n >> p;

    v<int> a(n);
    v<array<int, 2>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    sparse_table<int, op, e> stable(a);

    DSU ds(n);
    set<int> alive;
    for (int i = 0; i < n; i++)
        alive.insert(i);
    int ans = 0;
    for (auto& [_, j] : b) {
        if (a[j] > p) continue;

        int l = j, r = j;
        int lo = 0, hi = j;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (stable.prod(mid, j + 1) == a[j])
                l = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }

        lo = j, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (stable.prod(j, mid + 1) == a[j])
                r = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }

        l = ds.find(l), r = ds.find(r);
        auto it = alive.lower_bound(l);
        v<int> kill;
        while (it != alive.end() and *it <= r) {
            kill.push_back(*it);
            if (ds.merge(*it, l))
                ans += a[j];
            it++;
        }
        l = ds.find(l);
        for (int& x : kill)
            if (x != l)
                alive.erase(x);
    }

    for (int i = 0; i < n - 1; i++)
        if (ds.merge(i, i + 1))
            ans += p;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}