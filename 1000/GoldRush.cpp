#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

bool solve(int n, int m) {
    if (m == n)
        return true;
    if (n % 3 != 0 or m > n)
        return false;
    return solve(2 * n / 3, m) or solve(n / 3, m);
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n, m; cin >> n >> m;
        cout << (solve(n, m) ? "YES" : "NO") nl;
    }

    return 0;
}