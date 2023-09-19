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

        if (n % 3 == 0) {
            cout << n / 3 << " " << n / 3 + 1 << " " << n / 3 - 1 nl;
        }
        else {
            int diff = 3 - n % 3;
            n += diff;
            int h1 = n / 3;
            int h2 = n / 3 + 1;
            int h3 = n / 3 - 1 - diff;
            if (not h3) {h3++; h1--;}
            cout << h1 << " " << h2 << " " << h3 nl;
        }
    }

    return 0;
}