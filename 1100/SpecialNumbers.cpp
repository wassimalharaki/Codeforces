#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

const int mod = 1e9 + 7;

int binpow(int a, int b, const int m = 1e9 + 7) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n, k; cin >> n >> k;

        vi bits;
        while (k) {
            bits.pb(k & 1);
            k >>= 1;
        }

        int answ = 0;
        for (int i = 0; i < bits.size(); i++)
            if (bits[i])
                answ = (answ + binpow(n, i)) % mod;
        cout << answ nl;
    }

    return 0;
}