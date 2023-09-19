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

        if ((n & 1) == 0) {
            cout << 0 nl;
            continue;
        }

        string s = to_string(n);

        if (((s[0] - '0') & 1) == 0) {
            cout << 1 nl;
            continue;
        }
        bool possible = false;
        for (int i = 0; i < s.size(); i++)
            if (((s[i] - '0') & 1) == 0) {
                possible = true;
                break;
            }
        if (possible) {
            cout << 2 nl;
        }
        else {
            cout << -1 nl;
        }
    }

    return 0;
}