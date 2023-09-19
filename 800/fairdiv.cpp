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

        int one = 0;
        int two = 0;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a == 1)
                one++;
            if (a == 2)
                two++;
        }

        int sum = one + 2 * two;
        int half = sum / 2;

        if (sum % 2 == 1) {
            cout << "NO" nl;
            continue;
        }

        if (one >= half) {
            cout << "YES" nl;
            continue;
        }

        if (half % 2 == 0) {
            cout << "YES" nl;
        }
        else if (one > 0) {
            cout << "YES" nl;
        }
        else 
            cout << "NO" nl;
    }

    return 0;
}