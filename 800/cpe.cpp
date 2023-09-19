#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX

int32_t main() {
    fast

    int t; cin >> t;

    while (t--) {
        int a, b, n; cin >> a >> b >> n;

        if (a < b)
            swap(a, b);
        
        int steps = 0;

        while (a <= n && b <= n) {
            b += a;
            steps++;
            if (b > n)
                break;
            a += b;
            steps++;
        }

        cout << steps nl;
    }

    return 0;
}