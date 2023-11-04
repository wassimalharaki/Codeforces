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

    int sumx = 0, sumy = 0, sumz = 0;
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        sumx += x;
        sumy += y;
        sumz += z;
    }

    cout << (sumx == 0 and sumy == 0 and sumz == 0 ? "YES" : "NO");

    return 0;
}