#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

int32_t main() {
    fast

    int t;

    cin >> t;

    while(t--) {
        int x, y, n;

        cin >> x >> y >> n;

        int k = n / x * x + y;
        while (k > n)
            k -= x;

        cout << k nl;
    }

    return 0;
}