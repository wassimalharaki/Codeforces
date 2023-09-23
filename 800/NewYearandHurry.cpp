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

    int n, k; cin >> n >> k;
    int time = 240 - k;

    int lo = 1, hi = n;
    int middle, t;

    while (lo <= hi) {
        middle = (lo + hi) / 2;
        t = 5 * (1 + middle) * middle / 2;

        if (t > time)
            hi = middle - 1;
        else if (t < time)
            lo = middle + 1;
        else 
            break;
    }

    if (t > time)
        middle--;

    cout << middle;

    return 0;
}