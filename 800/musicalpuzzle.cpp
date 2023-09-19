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
        int n; cin >> n;
        string s; cin >> s;
        set<pair<char, char>> melodies;

        for (int i = 0; i < n - 1; i++)
            melodies.insert({s[i], s[i + 1]});

        cout << melodies.size() nl;
    }

    return 0;
}