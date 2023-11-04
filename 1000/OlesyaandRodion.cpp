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

    if (t == 10)
        if (n == 1)
            cout << -1;
        else {
            for (int i = 0; i < n - 1; i++)
                cout << 1;
            cout << 0;
        }
    else
        for (int i = 0; i < n; i++)
            cout << t;

    return 0;
}