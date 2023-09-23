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

    vi x(4); cin >> x[0] >> x[1] >> x[2] >> x[3];
    sort(all(x));
    cout << x[3] - x[2] << " " << x[3] - x[1] << " " << x[3] - x[0];

    return 0;
}