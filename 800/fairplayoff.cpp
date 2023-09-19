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

    while(t--) {
        v<pii> players(4);
        for (int i = 0; i < 4; i++) {
            cin >> players[i].first;
            players[i].second = i;
        }

        sort(all(players), greater<pii>());

        if (abs(players[0].second - players[1].second) == 1 && players[0].second + players[1].second != 3)
            cout << "NO" nl;
        else
            cout << "YES" nl;
    }

    return 0;
}