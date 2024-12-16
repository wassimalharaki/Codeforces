#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

mt19937_64 gen(random_device{}());
uniform_int_distribution<int> dist(1, 1e9);
int rnd() { return dist(gen); }

int n, m;
const int N = 2e3;
const int M = 26;
char s[N][N];
int a[N + N - 1][N + N - 1];
int64_t d[N + N][N + N];

int64_t prod(int i1, int j1, int i2, int j2) {
    return d[i2][j2] + d[i1][j1] - d[i2][j1] - d[i1][j2];
}

void solve() {
    cin >> n >> m;

    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));

    v<v<array<int, 2>>> ind(M);
    array<int, M> cnt; cnt.fill(0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            s[i][j] -= 'a';
            cnt[s[i][j]]++;
        }

    array<int64_t, M> val;
    for (int i = 0; i < M; i++)
        ind[i].resize(cnt[i]), val[i] = rnd();

    cnt.fill(0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            ind[s[i][j]][cnt[s[i][j]]++] = {i, j};
            a[i + j][j - i + n - 1] = val[s[i][j]];
        }

    for (int i = 1; i < n + m; i++)
        for (int j = 1; j < n + m; j++)
            d[i][j] = d[i - 1][j] + d[i][j - 1]
                + a[i - 1][j - 1] - d[i - 1][j - 1];

    int ans = 0;
    for (char c = 0; c < M; c++)
        for (auto& [i, j] : ind[c]) {
            int lo = 1, hi = min({i + 1, j + 1, n - i, m - j}), curr = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                int64_t x = prod(
                    i + j - mid + 1,
                    j - mid - i + n,
                    i + j + mid,
                    j + mid - i + n - 1
                );

                if (x == val[c] * (2 * mid * (mid - 1) + 1))
                    curr = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            ans += curr;
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