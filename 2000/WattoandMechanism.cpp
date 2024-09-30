#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

mt19937_64 gen(random_device{}());
uniform_int_distribution<int> dist(27, 1e8);

const array<const int, 2> M = {861999952, 725676706};
const array<const int, 2> B = {dist(gen), dist(gen)};
array<vector<int>, 2> P = {v{1ll}, v{1ll}}; 

using ai3 = array<int, 3>;

ai3 op(ai3 a, ai3 b) {
    return {
        (a[0] * P[0][b[2]] % M[0] + b[0]) % M[0],
        (a[1] * P[1][b[2]] % M[1] + b[1]) % M[1],
        a[2] + b[2]
    };
}

ai3 e() {
    return {0, 0, 0};
}

// O(n), O(log(n))
template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n, size, log;
    vector<S> d;

    segtree(int _n) : segtree(vector<S>(_n, e())) {}

    segtree(const vector<S>& a) {
        n = a.size();
        size = bit_ceil(n);
        log = __builtin_ctz(size);
        d.resize(size << 1, e());
        for (int i = 0; i < n; i++) d[size + i] = a[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    void update(int k) {
        d[k] = op(d[k << 1], d[(k << 1) + 1]);
    }

    int bit_ceil(int _n) {
        int x = 1;
        while (x < n) x <<= 1;
        return x;
    }

    void set(int p, S x) {
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        return d[p + size];
    }

    S prod(int l, int r) const {
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }
};

void solve() {
    int n, m; cin >> n >> m;

    set<array<int, 2>> have;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        for (int j = 0; j < 2; j++)
            while (P[j].size() < s.size() + 1)
                P[j].push_back(P[j].back() * B[j] % M[j]);

        v<ai3> t(s.size());
        for (int j = 0; j < (int) s.size(); j++)
            t[j] = {s[j], s[j], 1};

        auto x = segtree<ai3, op, e>(t).all_prod();
        have.insert({x[0], x[1]});
    }

    for (int i = 0; i < m; i++) {
        string s; cin >> s;

        for (int j = 0; j < 2; j++)
            while (P[j].size() < s.size() + 1)
                P[j].push_back(P[j].back() * B[j] % M[j]);

        v<ai3> t(s.size());
        for (int j = 0; j < (int) s.size(); j++)
            t[j] = {s[j], s[j], 1};

        bool ans = 0;
        segtree<ai3, op, e> seggy(t);
        for (int j = 0; j < (int) s.size() and not ans; j++) {
            for (int k = 0; k < 2 and not ans; k++) {
                for (int l = 0; l < 2; l++) {
                    t[j][l] -= 'a';
                    t[j][l] = (t[j][l] + 1) % 3;
                    t[j][l] += 'a';
                }
                seggy.set(j, t[j]);
                auto x = seggy.all_prod();
                if (have.count({x[0], x[1]}))
                    ans = 1;
            }
            for (int l = 0; l < 2; l++) {
                t[j][l] -= 'a';
                t[j][l] = (t[j][l] + 1) % 3;
                t[j][l] += 'a';
            }
            seggy.set(j, t[j]);
        }
        cout << (ans ? "YES" : "NO") << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}