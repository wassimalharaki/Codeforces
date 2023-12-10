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

int32_t main() {
    fast;

    int n, m; cin >> n >> m;
    vi dig_n(10), dig_m(10);

    while (n % 10) {
        dig_n[n % 10]++;
        n--;
    }

    while (m % 10) {
        dig_m[m % 10]++;
        m--;
    }

    for (int i = 0; i < 10; i++)
        dig_n[i] += n / 10, dig_m[i] += m / 10;
    
    int sum = dig_n[0] * dig_m[0] + dig_n[0] * dig_m[5]
        + dig_n[5] * dig_m[0] + dig_n[5] * dig_m[5];

    for (int i = 1; i < 10; i++)
        if (i != 5)
            sum += dig_n[i] * dig_m[10 - i] + dig_n[i] * dig_m[(15 - i) % 10];
    cout << sum nl;

    return 0;
}