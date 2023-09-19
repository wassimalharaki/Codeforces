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
        int a, p;

        cin >> a;

        int nb = 0;

        for (int i = 0; i < 3; i++) {
            cin >> p;
            if (p > a)
                nb++;
        }

        cout << nb nl;
    }

    return 0;
}