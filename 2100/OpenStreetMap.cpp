#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    v c(n, v<int>(m));

    int prev, x, y, z;
    cin >> prev >> x >> y >> z;
    c[0][0] = prev;

    for (int i = 1; i < n * m; i++)
        c[i / m][i % m] = prev = (prev * x + y) % z;
    
    v d(n, v<int>(m - b + 1));
    deque<int> mono;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b - 1; j++) {
            while (mono.size() and c[i][mono.front()] >= c[i][j])
                mono.pop_front();
            mono.push_front(j);
        }
        for (int j = b - 1; j < m; j++) {
            while (mono.size() and c[i][mono.front()] >= c[i][j])
                mono.pop_front();
            while (mono.size() and j - mono.back() >= b)
                mono.pop_back();
            mono.push_front(j);
            d[i][j - b + 1] = c[i][mono.back()];
        }
        mono.clear();
    }

    int ans = 0;
    for (int j = 0; j < m - b + 1; j++) {
        for (int i = 0; i < a - 1; i++) {
            while (mono.size() and d[mono.front()][j] >= d[i][j])
                mono.pop_front();
            mono.push_front(i);
        }
        for (int i = a - 1; i < n; i++) {
            while (mono.size() and d[mono.front()][j] >= d[i][j])
                mono.pop_front();
            while (mono.size() and i - mono.back() >= a)
                mono.pop_back();
            mono.push_front(i);
            ans += d[mono.back()][j];
        }
        mono.clear();
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