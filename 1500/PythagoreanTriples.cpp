#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

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

vi divisors(int n) {
    vi divs;
 
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divs.push_back(i);
 
    for (int i = divs.size() - 1; i >= 0; i--)
        if (n / divs[i] != divs[i])
            divs.push_back(n / divs[i]);
 
    return divs;
}
 
void solve() {
    int n; cin >> n;
 
    vi nums = divisors(n);
    set<int> divs;
    for (int& i : nums)
        for (int& j : nums)
            divs.insert(i * j);
    
    for (int i : divs) {
        int x = i, y = n * n / i;
        if (x >= y) break;
        if ((x + y) & 1) continue;
        int c = (x + y) / 2, a = c - x;
        if ((c - a) * (c + a) == n * n) {
            cout << a << " " << c;
            return;
        }
    }
 
    for (int a = 1; a <= 5e4; a++) {
        if (a * a >= n * n) break;
        int b = n * n - a * a;

        int lo = 0, hi = 1e9;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (mid * mid == b) {
                cout << a << " " << b;
                return;
            }
            else if (mid * mid > b)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
    }
    cout << -1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}