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

void solve() {
    int n, m; cin >> n >> m;

    v<set<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    auto was = [&](int i) -> bool {
        return not adj[i].empty() and *(--adj[i].end()) > i;
    };

    int c = 0;
    for (int i = 1; i <= n; i++)
        c += was(i);

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b;
            bool was_a = was(a), was_b = was(b);
            adj[a].insert(b);
            adj[b].insert(a);
            bool is_a = was(a), is_b = was(b);
            if (not was_a and is_a)
                c++;
            if (not was_b and is_b)
                c++;
        }
        else if (t == 2) {
            int a, b; cin >> a >> b;
            bool was_a = was(a), was_b = was(b);
            adj[a].erase(b);
            adj[b].erase(a);
            bool is_a = was(a), is_b = was(b);
            if (was_a and not is_a)
                c--;
            if (was_b and not is_b)
                c--;
        }
        else
            cout << n - c << nl;
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