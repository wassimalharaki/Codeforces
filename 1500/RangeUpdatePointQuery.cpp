#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
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
  
        lazy_segtree(int n) : lazy_segtree(vi(n, 0)) {}

        lazy_segtree(const vi& nums) {
            n = nums.size();
            size = bit_ceil(n);
            log = __builtin_ctzll(size);
            d = vi((size << 1), 0);
            lz = vi(size, 0);
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
        vi d, lz;

        void update(int k) { d[k] = d[k << 1] + d[(k << 1) + 1]; }

        void all_apply(int k, int f) {
            d[k] = f + d[k];
            if (k < size) lz[k] = f + lz[k];
        }

        void push(int k) {
            all_apply(k << 1, lz[k]);
            all_apply((k << 1) + 1, lz[k]);
            lz[k] = 0;
        }

        int bit_ceil(int n) {
            int x = 1;
            while (x < n) x <<= 1;
            return x;
        }
};

void solve() {
    int n, q; cin >> n >> q;
 
    vi nums(n);
    for (int& a : nums) cin >> a;
    lazy_segtree seggy(n);
 
    while (q--) {
        int a; cin >> a;
        if (a == 1) {
            int l, r; cin >> l >> r;
            seggy.apply(l - 1, r, 1);
        }
        else {
            int x; cin >> x;
            x--;
            int y = seggy.get(x);
            seggy.set(x, 0);
            while (y--) {
                string s = to_string(nums[x]);
                nums[x] = 0;
                for (char& c : s)
                    nums[x] += c - '0';
                if (nums[x] < 10)
                    y = 0;
            }
            cout << nums[x] << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}