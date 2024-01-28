#include <bits/stdc++.h>

using namespace std;

void dbg_out() { cerr << '\n'; }
template<typename T> void dbg_out(vector<T>& a) { for (auto& b : a) cerr << ' ' << b; cerr << '\n'; }
template<typename H, typename... T> void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#ifdef WASSIM
#define dbg(...) cerr << '[' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

struct lazy_segtree {

    public:
  
        lazy_segtree(int n) : lazy_segtree(v<int>(n, 0)) {}

        lazy_segtree(const vi& nums) {
            n = nums.size();
            size = bit_ceil(n);
            log = __builtin_ctz(size);
            d = vi(2 * size, 0);
            lz = v<int>(size, 0);
            for (int i = 0; i < n; i++) d[size + i] = nums[i];
            for (int i = size - 1; i >= 1; i--) update(i);
        }

        void set(int p, int x) {
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        int get(int p) {
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            return d[p];
        }

        int sum(int l, int r) {
            assert(0 <= l && l <= r && r <= n);
            if (l == r) return 0;

            l += size;
            r += size;

            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }

            int sml = 0, smr = 0;
            while (l < r) {
                if (l & 1) sml = sml + d[l++];
                if (r & 1) smr = d[--r] + smr;
                l >>= 1;
                r >>= 1;
            }

            return sml + smr;
        }

        int all_sum() { return d[1]; }

        void apply(int p, int f) {
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = f + d[p];
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        void apply(int l, int r, int f) {
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
    v<int> d;
    v<int> lz;

    void update(int k) { d[k] = d[2 * k] + d[2 * k + 1]; }

    void all_apply(int k, int f) {
        d[k] = f + d[k];
        if (k < size) lz[k] = f + lz[k];
    }

    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = 0;
    }

    int bit_ceil(int n) {
        int x = 1;
        while (x < n) x <<= 1;
        return x;
    }
};

void solve() {
    int n, k, q; cin >> n >> k >> q;
    lazy_segtree seggy(2e5);

    while (n--) {
        int l, r; cin >> l >> r;
        seggy.apply(l - 1, r, 1);
    }

    for (int i = 0; i < 2e5; i++)
        seggy.set(i, seggy.get(i) >= k);

    while (q--) {
        int l, r; cin >> l >> r;
        cout << seggy.sum(l - 1, r) << nl;
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