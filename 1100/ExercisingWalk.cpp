#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        vi horz(2), vert(2);
        cin >> horz[0] >> horz[1] >> vert[0] >> vert[1];
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        if (x == x1 and x1 == x2 and (horz[0] or horz[1])) {
            cout << "NO" nl;
            continue;
        }

        if (y == y1 and y1 == y2 and (vert[0] or vert[1])) {
            cout << "NO" nl;
            continue;
        }

        int min = std::min(horz[0], horz[1]);
        horz[0] -= min; horz[1] -= min;
        min = std::min(vert[0], vert[1]);
        vert[0] -= min; vert[1] -= min;

        string answ = "YES";
        if (x - horz[0] < x1)
            answ = "NO";
        else if (x + horz[1] > x2)
            answ = "NO";
        else if (y - vert[0] < y1)
            answ = "NO";
        else if (y + vert[1] > y2)
            answ = "NO";
        cout << answ nl;
    }

    return 0;
}