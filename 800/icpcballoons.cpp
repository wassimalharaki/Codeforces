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

    int n;

    int t; cin >> t;
    while (t--) {

    vi letters(26, 0);

    int balloons = 0;
        cin >> n;

        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            if (letters[c - 'A'] == 0) {
                letters[c - 'A'] = 1;
                balloons += 2;
            }
            else {
                balloons++;
            }
        }

        cout << balloons nl;
    }

    return 0;
}