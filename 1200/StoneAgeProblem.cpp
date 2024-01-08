#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

int op(int a, int b) {
    return a + b;
}

int e() {
    return 0;
}

int mapping(int x, int i) {
    return x;
}

int composition(int x1, int x2) {
    return x1;
}

int id() {
    return 0;
}

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {

    public:
  
        lazy_segtree(int n) : lazy_segtree(v<S>(n, e())) {}

        lazy_segtree(const v<S>& nums) {
            n = nums.size();
            size = bit_ceil((unsigned int) n);
            log = __builtin_ctz(size);
            d = v<S>(size << 1, e());
            lz = v<F>(size, id());
            for (int i = 0; i < n; i++) d[size + i] = nums[i];
            for (int i = size - 1; i >= 1; i--) update(i);
        }

        void set(int p, S x) {
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        S get(int p) {
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            return d[p];
        }

        S prod(int l, int r) {
            if (l == r) return e();

            l += size;
            r += size;

            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }

            S sml = e(), smr = e();
            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }

            return op(sml, smr);
        }

        S all_prod() { return d[1]; }

        void apply(int p, F f) {
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = mapping(f, d[p]);
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        void apply(int l, int r, F f) {
            if (l == r) return;

            l += size;
            r += size;

            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }

            {
                int l2 = l, r2 = r;
                while (l < r) {
                    if (l & 1) all_apply(l++, f);
                    if (r & 1) all_apply(--r, f);
                    l >>= 1;
                    r >>= 1;
                }
                l = l2;
                r = r2;
            }

            for (int i = 1; i <= log; i++) {
                if (((l >> i) << i) != l) update(l >> i);
                if (((r >> i) << i) != r) update((r - 1) >> i);
            }
        }

  private:
    int n, size, log;
    v<S> d;
    v<F> lz;

    void update(int k) { d[k] = op(d[k << 1], d[(k << 1) + 1]); }
    
    void all_apply(int k, F f) {
        if (f == 0)
            return;
        d[k] = (size << 1) / bit_ceil(k + 1) * mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }

    void push(int k) {
        all_apply(k << 1, lz[k]);
        all_apply((k << 1) + 1, lz[k]);
        lz[k] = id();
    }

    unsigned int bit_ceil(unsigned int n) {
        unsigned int x = 1;
        while (x < (unsigned int)(n)) x <<= 1;
        return x;
    }
};

void solve() {
    int n, q; cin >> n >> q;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    lazy_segtree<int, op, e, int, mapping, composition, id> lz(nums);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x;
            i--;
            lz.set(i, x);
        }
        else {
            int x; cin >> x;
            lz.apply(0, n, x);
        }
        cout << lz.all_prod() nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}