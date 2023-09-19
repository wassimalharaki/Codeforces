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

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        if (m % 2 == 0) {
            cout << n * m / 2 nl;
            continue;
        }

        int answ = n * (m - 1) / 2;
        answ += (n + 1) / 2;
        cout << answ nl;
    }

    return 0;
}