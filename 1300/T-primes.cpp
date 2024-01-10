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

v<bool> is_prime;
void build(int n) {
    is_prime = v<bool>(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;

    for (int i = 4; i <= n; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i <= n; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i * 2)
                is_prime[j] = 0;
}

void solve() {
    int n; cin >> n;

    int lo = 1, hi = 1e6, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (mid * mid > n)
            hi = mid - 1;
        else if (mid * mid < n)
            lo = mid + 1;
        else
            break;
    }
    cout << (mid * mid == n and is_prime[mid] ? "YES" : "NO") nl;
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