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
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

struct segtree {
    
    public:
  
        segtree(int n) : segtree(vi(n, 0)) {}

        segtree(const vi& nums) {
            n = nums.size();
            size = bit_ceil((unsigned int) n);
            log = __builtin_ctz(size);
            d = vi(2 * size, 0);
            for (int i = 0; i < n; i++) d[size + i] = nums[i];
            for (int i = size - 1; i >= 1; i--) update(i);
        }

        void set(int p, int x) {
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        int get(int p) const {
            return d[p + size];
        }

        int sum(int l, int r) const {
            int sml = 0, smr = 0;
            l += size;
            r += size;

            while (l < r) {
                if (l & 1) sml = sml + d[l++];
                if (r & 1) smr = d[--r] + smr;
                l >>= 1;
                r >>= 1;
            }
            return sml + smr;
        }

        int all_sum() const { return d[1]; }

    private:

        int n, size, log;
        vi d;

        void update(int k) { d[k] = d[2 * k] + d[2 * k + 1]; }
        
        unsigned int bit_ceil(unsigned int n) {
            unsigned int x = 1;
            while (x < (unsigned int)(n)) x <<= 1;
            return x;
        }
};

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;
    segtree st(n);

    int answ = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] >= i + 1) continue;
        st.set(i, 1);
        answ += st.sum(0, max(0ll, nums[i] - 1));
    }
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}