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

vi spf, primes;
void build(int n) {
    spf = vi(n + 1);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.pb(i);
        }
        for (int j = 0; i * primes[j] <= n; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i])
                break;
        }
    }
}

void solve() {
    int n; cin >> n;

    unordered_map<int, int, custom_hash> map;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        while (a != 1)
            map[spf[a]]++, a /= spf[a];
    }

    for (auto& [key, val] : map)
        if (val % n) {
            cout << "NO" nl;
            return;
        }
    cout << "YES" nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build(1e6);
    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}