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
        string s; cin >> s;
        int n = s.size();

        if (stoi(s) % 7 == 0)
            cout << s nl;
        else {
            for (int i = 1; i < 10; i++) {
                s[n - 1] = to_string(i)[0];
                if (stoi(s) % 7 == 0 && s[n - 1] != '0') {
                    cout << s nl;
                    break;
                }
            }
        }
    }

    return 0;
}