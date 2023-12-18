#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

struct lazy_segtree {

    public:
  
        lazy_segtree(int n) : lazy_segtree(v<int>(n, 0)) {}

        lazy_segtree(const vi& nums) {
            n = nums.size();
            size = bit_ceil((unsigned int) n);
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

    unsigned int bit_ceil(unsigned int n) {
        unsigned int x = 1;
        while (x < (unsigned int)(n)) x *= 2;
        return x;
    }
};

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        vpii nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i].F, nums[i].S = i;
        sort(all(nums));

        vi positions(n);
        iota(all(positions), 0ll);

        lazy_segtree lzseg(positions);
        vvi swaps;
        for (int i = 0; i < n; i++) {
            int real = lzseg.get(nums[i].S);
            if (real == 0) {
                lzseg.apply(nums[i].S + 1, n, -1);
                continue;
            }
            lzseg.apply(nums[i].S + 1, n, -1);
            swaps.pb({i + 1, real + 1 + i, real});
        }

        cout << swaps.size() nl;
        for (int i = 0; i < swaps.size(); i++)
            cout << swaps[i][0] << " " << swaps[i][1] << " " << swaps[i][2] nl;
    }

    return 0;
}