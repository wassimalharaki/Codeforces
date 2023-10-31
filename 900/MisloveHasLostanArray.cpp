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

    int n, l, r; cin >> n >> l >> r;

    int min = (1 << l) - 1 + n - l;
    int max = (1 << r) - 1 + (n - r) * (1 << (r - 1));
    cout << min << " " << max;
    
    return 0;
}