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

int32_t main() {
    fast

    int t;

    cin >> t;

    while (t--) {
        int h, m; cin >> h >> m;

        int total = 60 - m; h++;
        total += (24 - h) * 60;
        cout << total nl;
    }

    return 0;
}