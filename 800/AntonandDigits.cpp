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

    int k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;

    int a = min(k2, min(k5, k6));
    k2 -= a;

    cout << a * 256 + min(k2, k3) * 32 nl;

    return 0;
}