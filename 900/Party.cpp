#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int height(int src, v<vi>& adj, vi& heights) {
    if (heights[src] != -1)
        return heights[src];
    
    int max_height = 1;
    for (auto child : adj[src])
        max_height = max(max_height, 1 + height(child, adj, heights));
    heights[src] = max_height;
    return max_height;
}

int32_t main() {
    fast;

    int n; cin >> n;

    v<vi> adj(n);
    for (int i = 0; i < n; i++) {
        int u; cin >> u; u--;
        if (u == -2)
            continue;
        adj[u].pb(i);
    }

    int max_height = -1;
    vi heights(n, -1);
    for (int i = 0; i < n; i++)
        max_height = max(max_height, height(i, adj, heights));
    cout << max_height;
    return 0;
}