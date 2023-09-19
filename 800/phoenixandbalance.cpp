#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX

int32_t main() {
    fast

    int t;

    cin >> t;

    while(t--) {
        int n; cin >> n;
        int sum = pow(2, n + 1) - 2;
        int half = sum;
        half -= pow(2, n);
        for (int i = 1; i < n / 2; i++) {
            half -= pow(2, i);
        }

        cout << abs((sum - half) - half) nl;
    }

    return 0;
}