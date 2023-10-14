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
        int n; cin >> n;

        int time = n / 6 * 15; n %= 6;
        if (n) {
            if (n <= 2)
                time += 5;
            else if (n <= 4)
                time += 10;
            else
                time += 15;
        }
        time < 15 ? cout << 15 nl : cout << time nl;
    }

    return 0;
}