#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 63;

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(m);
    for (int& x : a) cin >> x;
    int sum = accumulate(a.begin(), a.end(), 0ll);
    int k = sum - n;

    if (sum < n) {
        cout << -1 << nl;
        return;
    }
    
    array<int, N> bits; bits.fill(0);
    for (int& x : a)
        bits[__lg(x)]++;

    array<int, N> me, trash;
    me.fill(0), trash.fill(0);
    for (int i = 0; i < N; i++)
        if ((1ll << i) & n)
            me[i]++;
    for (int i = 0; i < N; i++)
        if ((1ll << i) & k)
            trash[i]++;
    
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (me[i]) {
            me[i]--;
            if (bits[i])
                bits[i]--;
            else {
                int need = 2;
                for (int j = i - 1; j >= 0 and need; j--) {
                    int sub = min(need, bits[j]);
                    bits[j] -= sub;
                    need -= sub;
                    need <<= 1;
                }
            }
        }

        if (trash[i]) {
            trash[i]--;
            if (bits[i])
                bits[i]--;
            else {
                int need = 2;
                for (int j = i - 1; j >= 0 and need; j--) {
                    int sub = min(need, bits[j]);
                    bits[j] -= sub;
                    need -= sub;
                    need <<= 1;
                }
            }
        }

        ans += bits[i];
        if (i - 1 >= 0)
            bits[i - 1] += 2 * bits[i];
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}