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

int fact(int n) {
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}

int32_t main() {
    fast;

    int a, b; cin >> a >> b;
    cout << fact(min(a, b));

    return 0;
}