#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;

    unordered_map<int, int, custom_hash> map;
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] * primes[i] > n)
            break;
        while (n % primes[i] == 0)
            map[primes[i]]++, n /= primes[i];
    }
    if (n != 1) map[n]++;

    int max = 0, p = 0;
    for (auto& [key, val] : map)
        if (val > max)
            max = val, p = key;
    cout << max nl;
    for (int i = 0; i < max - 1; i++)
        cout << p << " ";
    int prod = p;
    for (auto& [key, val] : map)
        if (key != p) prod *= binpow(key, val);
    cout << prod nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build(1e5);
    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}