#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(N)
const int N = 2e5 + 1;
vector<int> spf(N), primes;
void build() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] < N; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i])
                break;
        }
    }
}

// O(log(n))
vector<array<int, 2>> prime_factors(int n) {
    if (primes.empty()) build();
    if (n == 1) return {};

    vector<array<int, 2>> pfs{{spf[n], 1}};
    n /= spf[n];
    while (n != 1) {
        if (pfs.back()[0] == spf[n])
            pfs.back()[1]++;
        else
            pfs.push_back({spf[n], 1});
        n /= spf[n];
    }

    return pfs;
}

const int mod = 998244353;

// O(log(b))
int binpow(int a, int b, const int m = mod) {
    a %= m;
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// O(log(min(a, b)))
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1;
    while (b) {
        int q = a / b;
        tie(x, x1) = make_pair(x1, x - q * x1);
        tie(y, y1) = make_pair(y1, y - q * y1);
        tie(a, b) = make_pair(b, a - q * b);
    }
    return a;
}

// O(log(min(a, b)))
int modinv(int a, const int m = mod) {
    int x, y;
    int g = gcd(a, m, x, y);
    return (g == 1 ? (x % m + m) % m : 0);
}

void solve() {
    int n; cin >> n;

    v<v<array<int, 3>>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int g = gcd(x, y);
        x /= g, y /= g;
        a--, b--;
        adj[a].push_back({b, x, y});
        adj[b].push_back({a, y, x});
    }

    v<int> val(n + 1), num(n + 1), deno(n + 1);
    auto dfs1 = [&](int u, int par, auto&& self) -> void {

        for (auto& [i, x, y] : adj[u]) {
            if (i == par) continue;

            v<array<int, 2>> delta_num, delta_deno;
            for (auto& [p, pw] : prime_factors(y)) {
                {
                    int sub = min(pw, deno[p]);
                    deno[p] -= sub;
                    delta_deno.push_back({p, - sub});
                    pw -= sub;
                }
                {
                    num[p] += pw;
                    delta_num.push_back({p, pw});
                }
            }

            for (auto& [p, pw] : prime_factors(x)) {
                {
                    int sub = min(pw, num[p]);
                    num[p] -= sub;
                    delta_num.push_back({p, - sub});
                    pw -= sub;
                }
                {
                    val[p] = max(val[p], deno[p] += pw);
                    delta_deno.push_back({p, pw});
                }
            }

            self(i, u, self);

            for (auto& [p, pw] : delta_num)
                num[p] -= pw;
            for (auto& [p, pw] : delta_deno)
                deno[p] -= pw;
        }
    };
    dfs1(0, -1, dfs1);

    int ans = 0;
    auto dfs2 = [&](int u, int p, int num, int deno, auto&& self) -> void {
        ans = (ans + num * modinv(deno)) % mod;
        for (auto& [i, x, y] : adj[u]) if (i != p)
            self(i, u, num * y % mod, deno * x % mod, self);
    };

    int x = 1, y = 1;
    for (int i = 1; i <= n; i++)
        x = x * binpow(i, val[i]) % mod;
    dfs2(0, -1, x, y, dfs2);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}