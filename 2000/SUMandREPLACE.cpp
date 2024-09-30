#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return a + b;
}

int e() {
    return 0;
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

// O(N)
const int N = 1e6 + 1;
vector<int> spf, primes;
void build() {
    spf.resize(N);
    spf[1] = 1;
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] < N; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i])
                break;
        }
    }
}

vector<array<int, 2>> prime_factors(int n) {
    if (n == 1) return {};
    if (primes.empty()) build();

    vector<array<int, 2>> pfs{{spf[n], 1}};
    n /= spf[n];
    while (n != 1) {
        if (pfs.back()[0] == spf[n])
            pfs.back()[1]++;
        else
            pfs.push_back({spf[n], 1});
        n /= spf[n];
    }

    return pfs;
}

v<int> go(N, 1);

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    set<int> alive;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 2)
            alive.insert(i);
    }
    segtree<int, op, e> seggy(a);

    while (m--) {
        int t, l, r; cin >> t >> l >> r; l--;

        if (t == 2) {
            cout << seggy.prod(l, r) << nl;
            continue;
        }

        v<int> kill;
        auto it = alive.lower_bound(l);
        while (it != alive.end() and *it < r) {
            seggy.set(*it, go[seggy.get(*it)]);
            if (seggy.get(*it) == 2)
                kill.push_back(*it);
            it++;
        }
        
        for (int& i : kill)
            alive.erase(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++)
        for (auto& [p, x] : prime_factors(i))
            go[i] *= x + 1;
    
    int T = 1;
    // cin >> T;
    while (T--) solve();
}