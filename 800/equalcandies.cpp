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
        int n;

        cin >> n;

        int min = LONG_LONG_MAX;

        vi candies(n);

        for (int i = 0; i < n ; i++) {
            cin >> candies[i];
            if (candies[i] < min)
                min = candies[i];
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += candies[i] - min;
        }

        cout << sum nl;
    }

    return 0;
}