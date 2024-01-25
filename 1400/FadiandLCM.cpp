#include <bits/stdc++.h>

using namespace std;

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

v<bool> is_prime;
vi primes = {2};
void build(int n) {
    is_prime = v<bool>(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;

    for (int i = 4; i <= n; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i <= n; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i * 2)
                is_prime[j] = 0;

    for (int i = 3; i <= n; i += 2)
        if (is_prime[i])
            primes.pb(i);
}

void solve() {
    build(1e6);
    int x; cin >> x;
    int n = x;

    vi nums;
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] * primes[i] > n) break;
        if (n % primes[i]) continue;
        nums.pb(primes[i]);
        n /= primes[i];
        while (n % primes[i] == 0)
            nums.back() *= primes[i], n /= primes[i];
    }
    if (n != 1) nums.pb(n);
    if (nums.empty()) nums.pb(1);

    pii ans{INF, INF};
    for (int mask = 0; mask < (1 << nums.size()); mask++) {
        int a = 1, b = 1;
        for (int i = 0; i < nums.size(); i++)
            if ((1 << i) & mask)
                a *= nums[i];
            else
                b *= nums[i];
        if (max(a, b) < max(ans.F, ans.S))
            ans = mp(a, b);
    }
    cout << ans.F << " " << ans.S;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}