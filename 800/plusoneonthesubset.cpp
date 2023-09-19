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

    while (t--) {
        int n;

        cin >> n;

        int max = -1;
        int min = LONG_LONG_MAX;

        for (int i = 0; i < n; i++) {
            int a;

            cin >> a;

            if (a > max)
                max = a;
            if (a < min)
                min = a;
        }

        cout << max - min nl;
    }

    return 0;
}