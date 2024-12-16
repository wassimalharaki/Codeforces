#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 61;
v<int> nimbers(N);

void solve() {
    int n; cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum ^= nimbers[x];
    }
    cout << (sum ? "NO" : "YES") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        nimbers[i] = x;
        if (++cnt == x + 1)
            cnt = 0, x++;
    }
    
    int T = 1;
    // cin >> T;
    while (T--) solve();
}