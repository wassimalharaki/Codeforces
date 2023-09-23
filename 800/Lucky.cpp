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

    int t; cin >> t;

    while (t--) {
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < 3; i++) {
            char c; cin >> c;
            sum1 += c - '0';
        }
        for (int i = 0; i < 3; i++) {
            char c; cin >> c;
            sum2 += c - '0';
        }

        sum1 == sum2 ? cout << "YES" nl : cout << "NO" nl;
    }

    return 0;
}