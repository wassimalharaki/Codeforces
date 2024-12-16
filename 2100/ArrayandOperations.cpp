#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(V^2*E)
template <class Cap> struct mf_graph {
    int n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;

    mf_graph(int _n) : n(_n), g(_n) {}

    int add_edge(int from, int to, Cap cap) {
        pos.push_back({from, g[from].size()});
        int from_id = g[from].size();
        int to_id = g[to].size();
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return pos.size();
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        auto e = g[pos[i].first][pos[i].second];
        auto re = g[e.to][e.rev];
        return edge{pos[i].first, e.to, e.cap + re.cap, re.cap};
    }

    vector<edge> edges() {
        int m = pos.size();
        vector<edge> result;
        for (int i = 0; i < m; i++)
            result.push_back(get_edge(i));
        return result;
    }

    void change_edge(int i, Cap new_cap, Cap new_flow) {
        auto& e = g[pos[i].first][pos[i].second];
        auto& re = g[e.to][e.rev];
        e.cap = new_cap - new_flow;
        re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }

    Cap flow(int s, int t, Cap flow_limit) {
        vector<int> level(n), iter(n);
        queue<int> q;

        auto bfs = [&]() {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            while (q.size()) q.pop();
            q.push(s);
            while (not q.empty()) {
                int v = q.front();
                q.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    q.push(e.to);
                }
            }
        };
        auto dfs = [&](int v, Cap up, auto&& self) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < (int) g[v].size(); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d = self(e.to, min(up - res, g[e.to][e.rev].cap), self);
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(t, flow_limit - flow, dfs);
            if (not f) break;
            flow += f;
        }
        return flow;
    }

    vector<char> min_cut(int s) {
        vector<char> visited(n);
        queue<int> q;
        q.push(s);
        while (not q.empty()) {
            int p = q.front();
            q.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap and not visited[e.to]) {
                    visited[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return visited;
    }
};

// O(Nlog(log(N)))
const int N = 4e4 + 1;
bitset<N> is_prime;
vector<int> primes;
void build() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    primes.push_back(2);
    for (int i = 4; i < N; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i < N; i += 2)
        if (is_prime[i])
            for (int j = i * i; j < N; j += i * 2)
                is_prime[j] = 0;

    for (int i = 3; i < N; i += 2)
        if (is_prime[i])
            primes.push_back(i);
}

// O(sqrt(n) / log(sqrt(n)))
vector<array<int, 2>> prime_factors(int n) {
    if (primes.empty()) build();

    vector<array<int, 2>> pfs;
    for (const int& x : primes) {
        if (x * x > n) break;
        if (n % x) continue;
        pfs.push_back({x, 0});
        while (n % x == 0) {
            n /= x;
            pfs.back()[1]++;
        }
    }
    if (n != 1) pfs.push_back({n, 1});
    
    return pfs;
}

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n), dpf;
    for (int& x : a) {
        cin >> x;
        for (auto& [p, y] : prime_factors(x))
            dpf.push_back(p);
    }
    sort(dpf.begin(), dpf.end());
    dpf.resize(unique(dpf.begin(), dpf.end()) - dpf.begin());

    v<array<int, 2>> e(m);
    for (auto& [x, y] : e) {
        cin >> x >> y;
        x--, y--;
        if (y & 1)
            swap(x, y);
    }

    int ans = 0;
    for (int& p : dpf) {
        mf_graph<int> mf(n + 2);
        for (auto& [x, y] : e) {
            int cx = a[x], cy = a[y];
            int cntx = 0, cnty = 0;
            while (cx % p == 0)
                cx /= p, cntx++;
            while (cy % p == 0)
                cy /= p, cnty++;
            mf.add_edge(x, y, min(cntx, cnty));
        }
        for (int i = 0; i < n; i++) {
            int x = a[i], cntx = 0;
            while (x % p == 0)
                x /= p, cntx++;
            if (i & 1)
                mf.add_edge(n, i, cntx);
            else
                mf.add_edge(i, n + 1, cntx);
        }
        ans += mf.flow(n, n + 1);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}