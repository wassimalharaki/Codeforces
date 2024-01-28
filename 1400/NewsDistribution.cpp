#include <bits/stdc++.h>

using namespace std;

void dbg_out() { cerr << endl; }
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

    int components() {
        int x = 0;
        for (int& i : p) if (i < 0) x++;
        return x;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    DSU ds(n);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        if (k == 0) continue;
        int a; cin >> a; a--;
        for (int i = 0; i < k - 1; i++) {
            int b; cin >> b;
            ds.merge(a, b - 1);
        }
    }

    for (int i = 0; i < n; i++)
        cout << ds.size(i) << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}