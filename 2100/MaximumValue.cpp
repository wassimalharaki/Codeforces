#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 2e6 + 1;

void solve() {
    int n; cin >> n;

    v<int> a(n), cnt(N);
    for (int& x : a)
        cin >> x, cnt[x] = x;

    for (int i = 1; i < N; i++)
        cnt[i] = max(cnt[i], cnt[i - 1]);
    
    int ans = 0;
    for (int i = 1; i < N; i++)
        if (cnt[i] == i)
            for (int j = 2 * i; j < N; j += i)
                ans = max(ans, cnt[j - 1] - j + i);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}