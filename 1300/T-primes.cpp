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

struct Sieve {
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

        // for (int i = 3; i <= n; i += 2)
        //     if (is_prime[i])
        //         primes.pb(i);
    }
} sieve;

int32_t main() {
    fast;

    sieve.build(1e6);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int lo = 1, hi = 1e6, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (mid * mid > a)
                hi = mid - 1;
            else if (mid * mid < a)
                lo = mid + 1;
            else
                break;
        }

        mid * mid == a and sieve.is_prime[mid] ?
            cout << "YES" nl:
            cout << "NO" nl;
    }

    return 0;
}