#include <bits/stdc++.h>

using namespace std;

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

struct DSU {
    vi p;

    DSU(int n) { p = vi(n, -1); }

    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

    int size(int x) { return - p[find(x)]; }

    bool same_set(int x, int y) { return find(x) == find(y); }

    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        return true;
    }
};

int binpow(int a, int b, const int m = 1e9 + 7) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;

    vvi nums(2, vi(n));
    for (int& a : nums[0]) cin >> a;
    for (int& a : nums[1]) cin >> a;

    DSU ds(n);
    for (int i = 0; i < n; i++)
        ds.merge(nums[0][i] - 1, nums[1][i] - 1);
    
    int a = 0;
    for (int i = 0; i < n; i++)
        if (ds.p[i] < 0) a++;
    cout << binpow(2, a) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}