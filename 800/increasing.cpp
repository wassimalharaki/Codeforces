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

    int n, t; cin >> t;

    while (t--) {
        set<int> s;

        cin >> n;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s.insert(a);
        }

        cout << ((s.size() == n)? "YES\n" : "NO\n");
    }

    return 0;
}