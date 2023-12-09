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

bool is_prime(int n) {
    if (n <= 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int32_t main() {
    fast;

    int T; cin >> T;
    vpii primes{
        {2, 3},
        {11, 13},
        {101, 103},
        {1009, 1013},
        {10007, 10009},
        {100003, 100019},
        {1000003, 1000033},
        {10000019, 10000079},
        {100000007, 100000037}
    };
    
    while (T--) {
        int a, b, c; cin >> a >> b >> c;
        int x = pow(10, c - 1);
        cout << primes[a - c].F * x << " " << primes[b - c].S * x nl;
    }

    return 0;
}