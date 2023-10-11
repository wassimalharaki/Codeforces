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

    int t; cin >> t;
    
    while (t--) {
        int n, H, M; cin >> n >> H >> M;

        int hours, mins, time = INF;
        for (int i = 0; i < n; i++) {
            int h, m; cin >> h >> m;

            int hdiff = 0, mdiff = m - M;
            if (mdiff < 0)
                mdiff += 60, hdiff--;
            hdiff += h - H;
            if (hdiff < 0)
                hdiff += 24;
            
            int tdiff = hdiff * 60 + mdiff;
            if (tdiff < time)
                hours = hdiff, mins = mdiff, time = tdiff;
        }
        cout << hours << " " << mins nl;
    }

    return 0;
}