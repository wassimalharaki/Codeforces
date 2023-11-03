#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

const int mod = 1000000007;

int32_t main() {
    fast;


    vi fact(1e5 + 1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 1e5 + 1; i++)
        fact[i] = (i * fact[i - 1]) % mod;

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;
        cout << fact[n] * ((n - 1) * n % mod) % mod nl;
    }

    return 0;
}