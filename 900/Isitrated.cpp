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

    bool change = 0, order = 1;
    int prev = INF;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (a != b)
            change = 1;
        if (a > prev)
            order = 0;
        prev = a;
    }
    change ? cout << "rated" : order ? cout << "maybe" : cout << "unrated";

    return 0;
}