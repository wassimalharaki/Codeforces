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
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;

    vi color(n);
    int c = 1;
    for (int i = 0; i < primes.size(); i++) {
        bool ok = 0;
        for (int j = 0; j < nums.size(); j++)
            if (color[j] == 0 and nums[j] % primes[i] == 0) {
                color[j] = c;
                ok = 1;
            }
        if (ok) c++;
    }
    cout << c - 1 << nl;
    for (int& i : color)
        cout << i << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build(5e2);
    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}