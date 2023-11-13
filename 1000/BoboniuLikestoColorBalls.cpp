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

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int even = 0, odd = 0, zeroes = 0;
        for (int i = 0; i < 4; i++) {
            int a; cin >> a;
            if (i != 3 and a == 0)
                zeroes++;
            a & 1 ? odd++ : even++;
        }
        cout << (even >= 3 or (even <= 1 and not zeroes) ? "YES" : "NO") nl;
    }

    return 0;
}