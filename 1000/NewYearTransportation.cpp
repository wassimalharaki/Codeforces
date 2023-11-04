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

    int n, t; cin >> n >> t;

    vi nums(n);
    for (int i = 1; i < n; i++)
        cin >> nums[i];
    
    vi portals(n);
    for (int i = 1; i < n; i++)
        portals[i] = i + nums[i];

    int pos = 1;
    for (int i = 1; i < n; i++) {
        if (pos == t)
            break;
        pos = portals[pos];
        if (pos > t or pos >= n)
            break;
    }
    cout << (pos == t ? "YES" : "NO") nl;

    return 0;
}