#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    string guest, host, pile; cin >> guest >> host >> pile;

    vi names(26, 0);
    vi p(26, 0);

    for (int i = 0; i < guest.size(); i++)
        names[guest[i] - 'A']++;

    for (int i = 0; i < host.size(); i++)
        names[host[i] - 'A']++;

    for (int i = 0; i < pile.size(); i++)
        p[pile[i] - 'A']++;

    for (int i = 0; i < 26; i++)
        if (names[i] != p[i]) {
            cout << "NO";
            return 0;
        }
    cout << "YES";

    return 0;
}