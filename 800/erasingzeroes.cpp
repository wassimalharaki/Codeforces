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
#define F first
#define S second

int32_t main() {
    fast

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        int last = 0;
        int start = 0;
        int remove = 0;
        int seq = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '1' && not start) {
                start = 1;
                last = i;
            }
            if (c == '0' && start) {
                remove++;
                seq++;
            }
            else {
                seq = 0;
            }
        }

        cout << remove - seq nl;
    }

    return 0;
}