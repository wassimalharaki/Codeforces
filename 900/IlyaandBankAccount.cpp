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

int32_t main() {
    fast;

    int n; cin >> n;
    if (n > -10) {
        cout << max(n, (int) 0);
        return 0;
    }
    n *= -1;

    int last = n % 10, blast = n / 10 % 10;
    n /= 100; n *= 10; n += min(last, blast); n *= -1;
    cout << n;
    
    return 0;
}