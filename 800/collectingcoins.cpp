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

    int t; cin >> t;

    while (t--) {
        int a, b, c, n; cin >> a >> b >> c >> n;
        int sum = a + b + c + n;
        int div = sum / 3;

        sum % 3 == 0 && a <= div && b <= div && c <= div ?
            cout << "YES" nl:
            cout << "NO" nl;
    }

    return 0;
}