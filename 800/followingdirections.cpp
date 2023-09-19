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
        int n; cin >> n;

        int x = 0, y = 0;

        bool yes = false;

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == 'U') {
                y++;
            }
            else if (c == 'D') {
                y--;
            }
            else if (c == 'L') {
                x--;
            }
            else {
                x++;
            }
            if (x == 1 && y == 1)
                yes = true;
        }

        cout << ((yes)? "YES\n" : "NO\n");
    }

    return 0;
}