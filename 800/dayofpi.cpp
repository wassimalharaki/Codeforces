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

    string pi = "314159265358979323846264338327";

    int t; cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int counter = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == pi[i])
                counter++;
            else
                break;
        }

        cout << counter nl;
    }

    return 0;
}