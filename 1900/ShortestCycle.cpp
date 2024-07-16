#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 60;

void solve() {
    int n; cin >> n;

    v<int> a(n);
    array<int, N> bits; bits.fill(0);
    for (int& x : a) {
        cin >> x;
        for (int i = 0; i < N; i++)
            bits[i] += ((1ll << i) & x) > 0;
    }

    for (int i = 0; i < N; i++)
        if (bits[i] > 2) {
            cout << 3 << nl;
            return;
        }
        
    sort(a.rbegin(), a.rend());
    while (a.size() and a.back() == 0)
        a.pop_back();
    n = a.size();
    
    //i know that n <= 120
    v<v<int>> adj(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] & a[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

    auto bfs = [&](int src) -> int {
        int ans = LLONG_MAX;
        v<int> dis(n, LLONG_MAX);
        queue<array<int, 3>> q;
        q.push({src, 0, -1});
        dis[src] = 0;

        while (q.size()) {
            auto [u, d, p] = q.front();
            q.pop();

            for (int& i : adj[u])
                if (i != p) {
                    if (dis[i] != LLONG_MAX)
                        ans = min(ans, d + dis[i] + 1);
                    else {
                        dis[i] = d + 1;
                        q.push({i, d + 1, u});
                    }
                }
        }
        return ans;
    };

    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, bfs(i));
    cout << (ans == LLONG_MAX ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}