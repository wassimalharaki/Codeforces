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
        int r;
        cin >> r;

        if (r >= 1900) {
            cout << "Division 1" nl;
        }
        else if (r >= 1600) {
            cout << "Division 2" nl;
        }
        else if (r >= 1400) {
            cout << "Division 3" nl;
        }
        else {
            cout << "Division 4" nl;
        }
    }

    return 0;
}