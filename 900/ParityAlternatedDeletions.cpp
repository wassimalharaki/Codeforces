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

    vi evens, odds;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a & 1 ? odds.pb(a) : evens.pb(a);
    }
    sort(all(evens)); sort(all(odds));

    int diff = evens.size() - odds.size();
    if (abs(diff) <= 1)
        cout << 0;
    else if (diff > 0) {
        int sum = 0;
        for (int i = 0; i < diff - 1; i++)
            sum += evens[i];
        cout << sum;
    }
    else {
        int sum = 0;
        for (int i = 0; i < - diff - 1; i++)
            sum += odds[i];
        cout << sum;
    }

    return 0;
}