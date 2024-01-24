#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n; cin >> n;

    string f = "Ashishgup\n", s = "FastestFinger\n";

    if (n == 1)
        cout << s;
    else if ((n & 1) or n == 2)
        cout << f;
    else {
        int a = 0;
        while (n != 1 and !(n & 1)) n >>= 1, a++;

        if (n == 1) {
            cout << s;
            return;
        }

        if (a > 1) {
            cout << f;
            return;
        }

        a = 0;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) a++;
        cout << (a ? f : s);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}