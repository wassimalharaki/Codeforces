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

    int n, m; cin >> n >> m;

    if (m % n != 0) {
        cout << -1;
        return 0;
    }

    int mult = m / n;

    int moves = 0;
    while (mult > 1) {
        if (mult % 3 != 0)
            break;
        mult /= 3;
        moves++;
    }

    while (mult > 1) {
        if (mult & 1)
            break;
        mult /= 2;
        moves++;
    }
    
    cout << (mult == 1 ? moves : -1);

    return 0;
}