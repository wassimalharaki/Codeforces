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

int divisors(int n, int lim) {
    int count = 0;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0 and n / i <= lim)
            i == n / i ? count++ : count += 2;
    return count;
}

int32_t main() {
    fast;

    int n, x; cin >> n >> x;
    cout << divisors(x, n);

    return 0;
}