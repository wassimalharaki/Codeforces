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

    string s = "codeforces";

    int t;

    cin >> t;

    while(t--) {
        char c; cin >> c;

        if (count(s.begin(), s.end(), c) >= 1) {
            cout << "YES" nl;
        }
        else
            cout << "NO" nl;
    }

    return 0;
}