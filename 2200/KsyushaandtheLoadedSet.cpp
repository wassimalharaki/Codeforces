#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

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

using ai2 = array<int, 2>;
const int N = 2e6 + 2, inf = 1e8;
segtree<int, op, e> seggy(N);

void solve() {
    int n; cin >> n;

    set<ai2> l, r;
    v<int> a;
    {
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push_back(x);
            seggy.set(x, 0);

            if (prev + 1 <= x - 1) {
                l.insert({prev + 1, x - 1});
                r.insert({x - 1, prev + 1});
                seggy.set(prev + 1, x - prev - 1);
                a.push_back(prev + 1);
            }

            prev = x;
        }

        l.insert({prev + 1, inf});
        r.insert({inf, prev + 1});
        seggy.set(prev + 1, inf);
        a.push_back(prev + 1);
    }

    auto walk = [&](int k) -> int {
        int i = 1;
        while (i < seggy.size)
            if (seggy.d[i << 1] >= k)
                i <<= 1;
            else
                i = (i << 1) + 1;
        return i - seggy.size;
    };

    int m; cin >> m;
    while (m--) {
        char c; cin >> c;

        if (c == '+') {
            int x; cin >> x;
            a.push_back(x);
            seggy.set(x, 0);

            auto [lb, rb] = *(--l.upper_bound({x, INT_MAX}));
            l.erase({lb, rb});
            r.erase({rb, lb});
            seggy.set(lb, -1);

            if (lb == x and rb == x) {
                ;
            }
            else if (lb == x) {
                l.insert({lb + 1, rb});
                r.insert({rb, lb + 1});
                seggy.set(lb + 1, rb - lb);
                a.push_back(lb + 1);
            }
            else if (rb == x) {
                l.insert({lb, rb - 1});
                r.insert({rb - 1, lb});
                seggy.set(lb, rb - lb);
            }
            else {
                l.insert({lb, x - 1});
                r.insert({x - 1, lb});
                seggy.set(lb, x - lb);

                l.insert({x + 1, rb});
                r.insert({rb, x + 1});
                seggy.set(x + 1, rb - x);
                a.push_back(x + 1);
            }
        }
        else if (c == '-') {
            int x; cin >> x;
            a.push_back(x);
            bool left = (*r.lower_bound({x - 1, 0}))[0] == x - 1;
            bool right = (*l.lower_bound({x + 1, 0}))[0] == x + 1;

            if (left and right) {
                auto [lr, ll] = *(--r.lower_bound({x, 0}));
                auto [rl, rr] = *(l.lower_bound({x, 0}));
                
                seggy.set(rl, -1);
                seggy.set(x, -1);

                r.erase({lr, ll});
                r.erase({rr, rl});

                l.erase({rl, rr});
                l.erase({ll, lr});

                r.insert({rr, ll});
                l.insert({ll, rr});

                seggy.set(ll, rr - ll + 1);
            }

            if (left and not right) {
                auto [lr, ll] = *(--r.lower_bound({x, 0}));

                seggy.set(x, -1);

                r.erase({lr, ll});
                l.erase({ll, lr});

                r.insert({lr + 1, ll});
                l.insert({ll, lr + 1});

                seggy.set(ll, seggy.get(ll) + 1);
            }

            if (not left and right) {
                auto [rl, rr] = *(l.lower_bound({x, 0}));
                
                seggy.set(x, -1);
                seggy.set(rl, -1);

                r.erase({rr, rl});
                l.erase({rl, rr});

                r.insert({rr, rl - 1});
                l.insert({rl - 1, rr});

                seggy.set(rl - 1, rr - rl + 2);
            }

            if (not left and not right) {
                seggy.set(x, 1);

                l.insert({x, x});
                r.insert({x, x});
            }
        }
        else {
            int k; cin >> k;
            int i = walk(k);
            cout << i << " ";
        }
    }

    for (int& x : a)
        seggy.set(x, -1);
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}