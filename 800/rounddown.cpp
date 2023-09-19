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
        int m; cin >> m;
        string s = to_string(m);
        int num = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            num *= 10;
        }

        cout << m - num nl;
    }

    return 0;
}