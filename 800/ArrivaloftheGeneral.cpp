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

    int n; cin >> n;

    int max = 0, min = INF;
    int iMax = -1, iMin = -1;

    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        if (h > max) {
            max = h;
            iMax = i;
        }
        if (h <= min) {
            min = h;
            iMin = i;
        }
    }
    
    if (iMax > iMin)
        cout << iMax + n - 2 - iMin;
    else 
        cout << iMax + n - 1 - iMin;

    return 0;
}