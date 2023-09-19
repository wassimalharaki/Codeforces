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
        string s;

        cin >> s;

        if (s.size() % 2 == 1) {
            cout << "NO" nl;
            continue;
        }

        cout << ((s.substr(0, s.size() / 2) == s.substr(s.size() / 2, s.size()))? "YES\n" : "NO\n");
    }

    return 0;
}