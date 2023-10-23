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

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        int max = -1, min = INF, cmax, cmin;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;

            if (a > max)
                max = a, cmax = 1;
            else if (a == max)
                cmax++;

            if (a < min)
                min = a, cmin = 1;
            else if (a == min)
                cmin++;
        }

        max != min ?
            cout << cmin * cmax * 2 nl:
            cout << cmax * (cmax - 1) nl;
    }

    return 0;
}